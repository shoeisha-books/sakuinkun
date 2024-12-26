#pragma once

#include "KeyWord.hpp"
#include "Reference.hpp"
#include <string>
#include <vector>
#include <compare>

struct IndexRecordData;

namespace sakuin
{
class IndexDesc;

/// <summary>
/// 索引のレコード
/// </summary>
class IndexRecord
{
public:
    IndexRecord()
        : IndexRecord(KeyWord(), KeyWord(), Reference())
    { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    IndexRecord(const KeyWord& mainKey, const KeyWord& subKey, const Reference& ref, const std::wstring& id = L"");

    /// <summary>
    /// ID取得
    /// </summary>
    /// <returns></returns>
    std::wstring getId()const;

    KeyWord getMainKey()const;
    KeyWord getSubKey()const;
    Reference getReference()const;

    /// <summary>
    /// Cインタフェース用構造体取得
    /// </summary>
    /// <returns></returns>
    bool getData(const IndexDesc& desc, IndexRecordData& data)const;

    /// <summary>
    /// サブキーの有無
    /// </summary>
    /// <returns></returns>
    bool hasSubKey()const;

    std::strong_ordering operator<=>(const IndexRecord& that)const;

private:
    std::wstring id_;
    KeyWord mainKey_;
    KeyWord subKey_;
    Reference ref_;
};
using IndexRecordList = std::vector<IndexRecord>;

extern IndexRecordList sortByYomi(const IndexRecordList& list, const std::wstring& repeat);
}
