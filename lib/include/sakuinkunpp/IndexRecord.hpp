/**
 * @file IndexRecord.hpp
 * @brief 索引レコードクラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once

#include "KeyWord.hpp"
#include "Reference.hpp"
#include <string>
#include <vector>
#include <compare>

// 前方宣言
struct IndexRecordData;

namespace sakuin
{
// 前方宣言
class IndexDesc;

/// <summary>
/// 索引レコードクラス
/// </summary>
class IndexRecord
{
public:
    /// <summary>
    /// デフォルトコンストラクタ
    /// </summary>
    IndexRecord()
        : IndexRecord(KeyWord(), KeyWord(), Reference())
    { }

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="mainKey">メインキーワード</param>
    /// <param name="subKey">サブキーワード</param>
    /// <param name="ref">参照</param>
    /// <param name="id">UUID（新規レコードの場合は空文字列）</param>
    IndexRecord(const KeyWord& mainKey, const KeyWord& subKey, const Reference& ref, const std::wstring& id = L"");

    /// <summary>
    /// ID取得
    /// </summary>
    /// <returns></returns>
    std::wstring getId()const;

    /// <summary>
    /// メインキーワード取得
    /// </summary>
    /// <returns></returns>
    KeyWord getMainKey()const;

    /// <summary>
    /// サブキーワード取得
    /// </summary>
    /// <returns></returns>
    KeyWord getSubKey()const;

    /// <summary>
    /// 参照取得
    /// </summary>
    /// <returns></returns>
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

/// <summary>
/// レコードリスト
/// </summary>
using IndexRecordList = std::vector<IndexRecord>;

/// <summary>
/// 読み用にソート
/// </summary>
/// <param name="list">元リスト</param>
/// <param name="repeat">省略文字</param>
/// <returns>ソート済みリスト</returns>
extern IndexRecordList sortByYomi(const IndexRecordList& list, const std::wstring& repeat);
}
