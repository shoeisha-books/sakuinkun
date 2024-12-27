/**
 * @file XlsxExport.cpp
 * @brief XLSXエクスポート用関数
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "XlsxExport.h"
#include "xlsxwriter.h"
#include "sakuin_def.h"
#include <filesystem>
#include <boost/nowide/convert.hpp>
#include <boost/algorithm/string.hpp>
#include <tuple>

namespace
{
    constexpr size_t KeyWordMaxLen = 128;
    constexpr size_t DispStrMaxLen = 128;
    constexpr size_t UuidMaxLen = 40;
    constexpr size_t UuidLen = 36;

template<typename T> void fillZero(T* arr, size_t count)
{
    std::memset(arr, 0, sizeof(T) * count);
}

KeyWordData createEmptyKeyWordData()
{
    KeyWordData ret;
    ret.word = new wchar_t[KeyWordMaxLen];
    fillZero(ret.word, KeyWordMaxLen);
    ret.yomi = new wchar_t[KeyWordMaxLen];
    fillZero(ret.yomi, KeyWordMaxLen);
    ret.word_len = KeyWordMaxLen;
    ret.yomi_len = KeyWordMaxLen;
    return ret;
}

IndexRecordData createEmptyRecordData()
{
    IndexRecordData ret;
    ret.main_key = createEmptyKeyWordData();
    ret.sub_key = createEmptyKeyWordData();

    ret.ref.disp_str = new wchar_t[DispStrMaxLen];
    ret.ref.disp_str_len = DispStrMaxLen;
    fillZero(ret.ref.disp_str, DispStrMaxLen);

    ret.uuid = new wchar_t[UuidMaxLen];
    ret.uuid_len = UuidLen;
    fillZero(ret.uuid, UuidMaxLen);

    return ret;
}

void freeKeyWordData(KeyWordData& data)
{
    delete[] data.word;
    delete[] data.yomi;
    data.yomi = nullptr;
    data.word = nullptr;
}
void freeRecordData(IndexRecordData& data)
{
    freeKeyWordData(data.main_key);
    freeKeyWordData(data.sub_key);
    delete[] data.ref.disp_str;
    data.ref.disp_str = nullptr;
    delete[] data.uuid;
    data.uuid = nullptr;
}
}

namespace sakuin
{
using ExportRecord = std::tuple<std::wstring, std::wstring, std::vector<std::wstring>>;

using ExportRecordList = std::vector<ExportRecord>;

ExportRecordList calcExportRecordList(const IndexRecordList& recordList, const IndexDesc& desc)
{
    auto sortedList = sortByYomi(recordList, desc.getRepeat());
    std::vector<IndexRecordData> dataList;
    for (const auto& record : sortedList)
    {
        IndexRecordData temp = createEmptyRecordData();
        record.getData(desc, temp);
        dataList.push_back(temp);
    }

    ExportRecordList ret;

    // 1個前のデータ
    KeyWordData mainKey = createEmptyKeyWordData();
    KeyWordData subKey = createEmptyKeyWordData();
    for (const auto& data : dataList)
    {
        std::wstring mainWord = mainKey.word;
        std::wstring subWord = subKey.word;

        if (mainWord == data.main_key.word)
        {
            if (subWord == data.sub_key.word)
            {
                std::get<2>(*(ret.end() -1)).push_back(data.ref.disp_str);
            }
            else
            {
                ExportRecord record;
                std::get<0>(record) = L"";
                std::get<1>(record) = data.sub_key.word;
                std::get<2>(record) = std::vector<std::wstring>({ data.ref.disp_str });
                ret.push_back(record);
            }
        }
        else
        {
            if (std::wstring newSubWord = data.sub_key.word ; !newSubWord.empty())
            {
                ExportRecord record;
                std::get<0>(record) = data.main_key.word;
                std::get<1>(record) = L"";
                std::get<2>(record) = std::vector<std::wstring>();
                ret.push_back(record);
            }
            ExportRecord record;
            std::get<0>(record) = data.main_key.word;
            std::get<1>(record) = data.sub_key.word;
            std::get<2>(record) = std::vector<std::wstring>({ data.ref.disp_str });
            ret.push_back(record);
        }

        mainKey = data.main_key;
        subKey = data.sub_key;
    }

    return ret;
}

bool exportXLSX(const std::wstring& fileName, const IndexRecordList& recordList, const IndexDesc& desc)
{

    auto workbook = workbook_new(boost::nowide::narrow(fileName).c_str());
    auto worksheet = workbook_add_worksheet(workbook, "index");

    // header
    worksheet_write_string(worksheet, 0, 0, "キーワード", nullptr);
    worksheet_write_string(worksheet, 0, 1, "サブキー", nullptr);
    worksheet_write_string(worksheet, 0, 2, "ページ", nullptr);

    // body
    auto exportRecordList = calcExportRecordList(recordList, desc);

    for (auto i = 0; i < exportRecordList.size(); i++)
    {
        worksheet_write_string(worksheet, i + 1, 0, boost::nowide::narrow(std::get<0>(exportRecordList[i])).c_str(), nullptr);
        worksheet_write_string(worksheet, i + 1, 1, boost::nowide::narrow(std::get<1>(exportRecordList[i])).c_str(), nullptr);
        worksheet_write_string(worksheet, i + 1, 2, boost::nowide::narrow(boost::algorithm::join(std::get<2>(exportRecordList[i]), L", ")).c_str(), nullptr);
    }

    workbook_close(workbook);

    return true;
}

std::wstring getXlsxVer()
{
    return boost::nowide::widen(LXW_VERSION);
}
}
