#pragma once

#include "sakuinkun/ReferenceType.h"

extern const wchar_t* LibSakuinVer;

#ifdef __cplusplus
extern "C"
{
#endif

// 基本的に利用者がメモリを確保する


// 索引ヘッダ
struct IndexDescData
{
    wchar_t* repeat = nullptr;
    int repeat_len = 0;
    int offset = 0;
    int roman_page_num = 0;
    bool roman_cap = true;
};

// キーワード
struct KeyWordData
{
    wchar_t* word = nullptr;    // 単語
    wchar_t* yomi = nullptr;    // 読み
    int word_len = 0;
    int yomi_len = 0;
};

// 参照データ
struct ReferenceData
{
    wchar_t* disp_str = nullptr;      // 表示文字列
    int disp_str_len = 0;
    int type = -1;                      // 参照タイプ
    int page = 0;                       // 元ページ
};

// 索引レコード
struct IndexRecordData
{
    KeyWordData main_key = {};
    KeyWordData sub_key = {};
    ReferenceData ref = {};
    wchar_t* uuid = nullptr;
    int uuid_len = 0;
    bool has_sub_key = false;
};

// 索引データ
struct IndexData
{
    IndexDescData desc = {};
    IndexRecordData* records = {};
    int record_num = 0;
};

#define VERSION_LENGTH 32
#ifdef __cplusplus
}
#endif