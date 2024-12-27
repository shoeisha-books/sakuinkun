/**
 * @file IndexRecord.cpp
 * @brief 索引レコードクラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "sakuinkunpp/IndexRecord.hpp"
#include "util.h"
#include "sakuin_def.h"
#include <algorithm>
#include <stdexcept>
#include <boost/nowide/convert.hpp>
#include <boost/algorithm/string.hpp>

using namespace sakuin;

namespace
{
IndexRecordList replaceSubYomiStr(const IndexRecordList& list, const std::wstring& from, const std::wstring& to)
{
    IndexRecordList ret;
    for (const auto& record : list)
    {
        auto subYomi = record.getSubKey().getYomi();
        boost::replace_all(subYomi, from, to);
        auto temp = IndexRecord(
            record.getMainKey(),
            KeyWord(record.getSubKey().getWord(), subYomi),
            record.getReference(),
            record.getId());
        ret.push_back(temp);
    }
    return ret;
}
}

IndexRecord::IndexRecord(const KeyWord& mainKey, const KeyWord& subKey, const Reference& ref, const std::wstring& id)
    : id_(id), mainKey_(mainKey), subKey_(subKey), ref_(ref)
{
    if (id_.empty())
    {
        id_ = getUUID();
    }
}

std::wstring IndexRecord::getId()const
{
    return id_;
}

bool IndexRecord::hasSubKey()const
{
    return subKey_.valid();
}

KeyWord IndexRecord::getMainKey()const
{
    return mainKey_;
}

KeyWord IndexRecord::getSubKey()const
{
    return subKey_;
}

Reference IndexRecord::getReference()const
{
    return ref_;
}

bool IndexRecord::getData(const IndexDesc& desc, IndexRecordData& data)const
{
    if (id_.size() != data.uuid_len)
    {
        throw std::runtime_error("Invalid ID:" + boost::nowide::narrow(id_));
        return false;
    }
    std::wcsncpy(data.uuid, id_.c_str(), id_.size());
    mainKey_.getData(data.main_key);
    subKey_.getData(data.sub_key);
    ref_.getData(desc, data.ref);

    data.has_sub_key = subKey_.valid();


    return true;
}

std::strong_ordering IndexRecord::operator<=>(const IndexRecord& that)const
{
    if (auto comp = mainKey_ <=> that.mainKey_ ; comp != 0)
    {
        return comp;
    }
    if (auto comp = subKey_ <=> that.subKey_; comp != 0)
    {
        return comp;
    }
    return ref_ <=> that.ref_;
}

namespace sakuin
{
IndexRecordList sortByYomi(const IndexRecordList& list, const std::wstring& repeat)
{
    // 繰り返し文字を\t（\u0009）に
    IndexRecordList ret = replaceSubYomiStr(list, repeat, L"\t");
    std::sort(ret.begin(), ret.end());
    return replaceSubYomiStr(ret, L"\t", repeat);
}
}
