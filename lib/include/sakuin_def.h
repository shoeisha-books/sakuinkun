/**
 * @file sakuin_def.h
 * @brief さくいんくん Cインタフェース用各種定義
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 */

#pragma once

#include "sakuinkun/ReferenceType.h"

extern const wchar_t* LibSakuinVer;

#ifdef __cplusplus
extern "C"
{
#endif

// ATTENTION! 基本的に利用者がメモリを確保・管理する

/// <summary>
/// 索引生成用設定
/// </summary>
struct IndexDescData
{
    wchar_t* repeat = nullptr;
    int repeat_len = 0;
    int offset = 0;
    int roman_page_num = 0;
    bool roman_cap = true;
};

/// <summary>
/// キーワード
/// </summary>
struct KeyWordData
{
    wchar_t* word = nullptr;    // 単語
    wchar_t* yomi = nullptr;    // 読み
    int word_len = 0;           // 文字列バッファサイズ
    int yomi_len = 0;           // 文字列バッファサイズ
};

/// <summary>
/// 参照データ
/// </summary>
struct ReferenceData
{
    wchar_t* disp_str = nullptr;        // 表示文字列
    int disp_str_len = 0;               // 文字列バッファサイズ
    int type = -1;                      // 参照タイプ
    int page = 0;                       // 元ページ（PDF上のページ番号）
};

/// <summary>
/// 索引レコード
/// </summary>
struct IndexRecordData
{
    KeyWordData main_key = {};          // メインキーワード
    KeyWordData sub_key = {};           // サブキーワード
    ReferenceData ref = {};             // 参照
    wchar_t* uuid = nullptr;            // UUID
    int uuid_len = 0;                   // 文字列バッファサイズ
    bool has_sub_key = false;           // サブキーあるか？（あまり意味ない）
};

/// <summary>
/// 索引データ
/// </summary>
struct IndexData
{
    IndexDescData desc = {};            // 設定
    IndexRecordData* records = {};      // レコード
    int record_num = 0;                 // 確保済みレコード件数
};

#define VERSION_LENGTH 32
#ifdef __cplusplus
}
#endif