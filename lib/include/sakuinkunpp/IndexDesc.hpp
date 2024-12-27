/**
 * @file IndexDesc.hpp
 * @brief 索引設定クラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once
#include <string>

// 前方宣言
struct IndexDescData;

namespace sakuin
{
/// <summary>
/// 索引設定記述クラス
/// </summary>
class IndexDesc
{
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="offset">オフセット</param>
    /// <param name="romanPageNum">ローマ数字のページ数</param>
    /// <param name="romanCap">ローマ数字は大文字か？</param>
    /// <param name="repeat">省略文字の指定（「～」とか）</param>
    IndexDesc(int offset, int romanPageNum, bool romanCap,
        const std::wstring& repeat);

    /// <summary>
    /// C用データ取得
    /// </summary>
    /// <param name="data">データインスタンス</param>
    /// <returns>true：成功、false：失敗</returns>
    bool getData(IndexDescData& data)const;

    /// <summary>
    /// オフセット取得
    /// </summary>
    /// <returns></returns>
    int getOffset()const;

    /// <summary>
    /// ローマ数字ページ数取得
    /// </summary>
    /// <returns></returns>
    int getRomanPageNum()const;

    /// <summary>
    /// ローマ数字は大文字か？
    /// </summary>
    /// <returns></returns>
    bool isRomanCap()const;

    /// <summary>
    /// 省略文字取得
    /// </summary>
    /// <returns></returns>
    std::wstring getRepeat()const;

private:
    int offset_ = 0;
    int romanPageNum_ = 0;
    bool romanCap_ = true;
    std::wstring repeat_ = L"";
};
}