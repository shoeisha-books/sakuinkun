/**
 * @file libsakuin.h
 * @brief Cインタフェース
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */
#pragma once

#include "sakuin_def.h"

#ifdef __cplusplus
/* C Interfaces*/
extern "C"
{
#endif


/// <summary>
/// 初期化（何するにも必要）
/// </summary>
/// <returns></returns>
DLLEXPORT void init_app();

/// <summary>
/// 初期化済みか？
/// </summary>
/// <returns></returns>
DLLEXPORT bool is_initialized();

/// <summary>
/// ライブラリバージョンの取得
/// </summary>
/// <param name="version"></param>
/// <returns></returns>
DLLEXPORT void get_lib_version(wchar_t* version);

/// <summary>
/// MeCab Modelバージョンの取得
/// </summary>
/// <param name="version"></param>
/// <returns></returns>
DLLEXPORT void get_mecab_model_version(wchar_t* version);

/// <summary>
/// MeCab Taggerバージョンの取得
/// </summary>
/// <param name="version"></param>
/// <returns></returns>
DLLEXPORT void get_mecab_tagger_version(wchar_t* version);

/// <summary>
/// Boostバージョンの取得
/// </summary>
/// <param name="version"></param>
/// <returns></returns>
DLLEXPORT void get_boost_version(wchar_t* version);

/// <summary>
/// XML2バージョンの取得
/// </summary>
/// <param name="version"></param>
/// <returns></returns>
DLLEXPORT void get_xml2_version(wchar_t* version);

/// <summary>
/// XlsxWriterのバージョン取得
/// </summary>
/// <param name="version"></param>
/// <returns></returns>
DLLEXPORT void get_xlsx_writer_version(wchar_t* version);

/// <summary>
/// Json読み込み
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
DLLEXPORT bool load_json(const wchar_t* fileName);

/// <summary>
/// Jsonへのセーブ
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
DLLEXPORT bool save_json(const wchar_t* fileName);

/// <summary>
/// Xmlからのインポート
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
DLLEXPORT bool import_xml(const wchar_t* fileName);

/// <summary>
/// Xlsxへのエクスポート
/// </summary>
/// <param name="fileName"></param>
/// <returns></returns>
DLLEXPORT bool export_xlsx(const wchar_t* fileName);

/// <summary>
/// レコードの数取得
/// </summary>
/// <returns></returns>
DLLEXPORT int get_index_num();

/// <summary>
/// 索引データ取得
/// </summary>
/// <param name="data"></param>
/// <param name="sort">読み用のソート</param>
/// <returns></returns>
DLLEXPORT bool get_index(IndexData* data, bool sort);

/// <summary>
/// 個別レコード取得
/// </summary>
/// <param name="uuid"></param>
/// <param name="data"></param>
/// <returns></returns>
DLLEXPORT bool get_record(const wchar_t* uuid, IndexRecordData* data);

/// <summary>
/// 設定をセット
/// </summary>
/// <param name="desc"></param>
/// <returns></returns>
DLLEXPORT void set_desc(const IndexDescData* desc);

/// <summary>
/// レコードの追加・更新
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
DLLEXPORT void add_and_update_record(const IndexRecordData* data);

/// <summary>
/// 終了処理
/// </summary>
/// <returns></returns>
DLLEXPORT void term_app();
#ifdef __cplusplus
}
#endif
