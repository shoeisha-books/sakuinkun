

#include "libsakuin.h"

#include "sakuinkunpp/SakuinKun.hpp"
#include <iostream>

const wchar_t* RangeMark = L"-";
const wchar_t* SeeMark = L"→";
const wchar_t* SeeAlsoMark = L"⇒";
const wchar_t* LibSakuinVer = L"3.0.0";

DLLEXPORT void initialize()
{
    sakuin::SakuinKun::getInstance().initialize();
}

DLLEXPORT bool is_initialized()
{
    return sakuin::SakuinKun::getInstance().isInitialized();
}

DLLEXPORT void get_lib_version(wchar_t* version)
{
    if (version == nullptr)
    {
        return;
    }
    std::wstring verStr = sakuin::SakuinKun::getLibVersion();
    std::wmemset(version, L'\0', VERSION_LENGTH);
    std::wcsncpy(version, verStr.data(), verStr.size());
}

DLLEXPORT void get_mecab_model_version(wchar_t* version)
{
    if (version == nullptr)
    {
        return;
    }
    std::wstring verStr = sakuin::SakuinKun::getMecabModelVersion();
    std::wmemset(version, L'\0', VERSION_LENGTH);
    std::wcsncpy(version, verStr.data(), verStr.size());
}

DLLEXPORT void get_mecab_tagger_version(wchar_t* version)
{
    if (version == nullptr)
    {
        return;
    }
    std::wstring verStr = sakuin::SakuinKun::getMecabModelVersion();
    std::wmemset(version, L'\0', VERSION_LENGTH);
    std::wcsncpy(version, verStr.data(), verStr.size());
}

DLLEXPORT void get_boost_version(wchar_t* version)
{
    if (version == nullptr)
    {
        return;
    }
    std::wstring verStr = sakuin::SakuinKun::getBoostVersion();
    std::wmemset(version, L'\0', VERSION_LENGTH);
    std::wcsncpy(version, verStr.data(), verStr.size());
}

DLLEXPORT void get_xml2_version(wchar_t* version)
{
    if (version == nullptr)
    {
        return;
    }
    std::wstring verStr = sakuin::SakuinKun::getXml2Version();
    std::wmemset(version, L'\0', VERSION_LENGTH);
    std::wcsncpy(version, verStr.data(), verStr.size());
}

DLLEXPORT void get_xlsx_writer_version(wchar_t* version)
{
    if (version == nullptr)
    {
        return;
    }
    std::wstring verStr = sakuin::SakuinKun::getXlsxWriterVersion();
    std::wmemset(version, L'\0', VERSION_LENGTH);
    std::wcsncpy(version, verStr.data(), verStr.size());
}

DLLEXPORT bool load_json(const wchar_t* fileName)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();

    if (!sakuin.isInitialized() || fileName == nullptr)
    {
        return false;
    }
    return sakuin.loadJson(fileName);
}

DLLEXPORT bool save_json(const wchar_t* fileName)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();

    if (!sakuin.isInitialized() || fileName == nullptr)
    {
        return false;
    }
    return sakuin.saveJson(fileName);
}

DLLEXPORT bool import_xml(const wchar_t* fileName)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();

    if (!sakuin.isInitialized() || fileName == nullptr)
    {
        return false;
    }
    
    return sakuin.importXML(fileName);
}

DLLEXPORT bool export_xlsx(const wchar_t* fileName)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();

    if (!sakuin.isInitialized() || fileName == nullptr)
    {
        return false;
    }

    return sakuin.exportXLSX(fileName);
}

DLLEXPORT int get_index_num()
{
    return sakuin::SakuinKun::getInstance().getRecordList().size();
}

DLLEXPORT bool get_index(IndexData* data, bool sort)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();
    if (!sakuin.isInitialized() || data == nullptr)
    {
        return false;
    }

    const auto RecordNum = data->record_num;
    auto desc = sakuin.getDesc();
    auto records = sort ?
        sakuin::sortByYomi(sakuin.getRecordList(), desc.getRepeat())
        : sakuin.getRecordList();


    if (records.size() != data->record_num)
    {
        // @TODO error
        return false;
    }
    if (!desc.getData(data->desc))
    {
        // @TODO error
        return false;
    }
    for (auto i = 0; i < records.size(); i++)
    {
        auto& outRecord = data->records[i];
        if (!records[i].getData(desc, outRecord))
        {
            // @TODO error
            return false;
        }
    }
    return true;
}

DLLEXPORT bool get_record(const wchar_t* uuid, IndexRecordData* data)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();
    if (!sakuin.isInitialized() || data == nullptr)
    {
        return false;
    }

    auto desc = sakuin.getDesc();
    auto record = sakuin::IndexRecord();
    if (!sakuin.getRecord(uuid, record))
    {
        return false;
    }
    return record.getData(desc, *data);
}

DLLEXPORT void set_desc(const IndexDescData* desc)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();
    if (!sakuin.isInitialized() || desc == nullptr)
    {
        return;
    }
    sakuin.setDesc(sakuin::IndexDesc(desc->offset, desc->roman_page_num, desc->roman_cap, desc->repeat));
}

DLLEXPORT void add_and_update_record(const IndexRecordData* data)
{
    auto& sakuin = sakuin::SakuinKun::getInstance();
    if (!sakuin.isInitialized() || data == nullptr)
    {
        return;
    }

    auto mainKey = sakuin::KeyWord(data->main_key.word, data->main_key.yomi);
    auto subKey = sakuin::KeyWord();
    if (data->has_sub_key)
    {
        subKey = sakuin::KeyWord(data->sub_key.word, data->sub_key.yomi);
    }

    ReferenceType refType = ReferenceType::Invalid;
    switch (data->ref.type)
    {
    case 0:
        refType = ReferenceType::Nombre;
        break;
    case 1:
        refType = ReferenceType::Range;
        break;
    case 2:
        refType = ReferenceType::See;
        break;
    case 3:
        refType = ReferenceType::SeeAlso;
        break;
    case 4:
        refType = ReferenceType::Manual;
        break;
    default:
        refType = ReferenceType::Invalid;
        break;
    }
    auto ref = sakuin::Reference(refType, data->ref.page, data->ref.disp_str);

    std::wstring uuid = L"";
    if (data->uuid)
    {
        uuid = data->uuid;
    }
    
    auto record = sakuin::IndexRecord(mainKey, subKey, ref, uuid);

    sakuin.addAndUpdateRecord(record);
}

DLLEXPORT void dummy()
{    
    auto& sakuin = sakuin::SakuinKun::getInstance();
    sakuin.initialize();

    auto xmlFile = L"c:/test/all.xfdf";
    
    sakuin::IndexDesc desc(0, 0, true, L"～");
    sakuin.setDesc(desc);

    if (!sakuin.importXML(xmlFile))
    {
        std::cout << "err: importXML" << std::endl;
    }

    if (!sakuin.saveJson(L"c:/test/index.json"))
    {
        std::cout << "err: saveJson" << std::endl;
    }

    if (!sakuin.loadJson(L"c:/test/index.json"))
    {
        std::cout << "err: loadJson" << std::endl;
    }

    if (!sakuin.exportXLSX(L"c:/test/test.xlsx"))
    {
        std::cout << "err: exportXLSX" << std::endl;
    }

    return;
}
