#pragma once

#include "sakuin_def.h"

#ifdef __cplusplus
/* C Interfaces*/
extern "C"
{
#endif
#ifdef WIN32
//#ifndef DLL_EXPORT
#define DLLEXPORT __declspec(dllexport)
//#endif
#else
#define DLLEXPORT export
#endif

DLLEXPORT void initialize();

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

DLLEXPORT void get_xlsx_writer_version(wchar_t* version);


DLLEXPORT bool load_json(const wchar_t* fileName);

DLLEXPORT bool save_json(const wchar_t* fileName);

DLLEXPORT bool import_xml(const wchar_t* fileName);

DLLEXPORT bool export_xlsx(const wchar_t* fileName);

DLLEXPORT int get_index_num();

DLLEXPORT bool get_index(IndexData* data, bool sort);

DLLEXPORT bool get_record(const wchar_t* uuid, IndexRecordData* data);

DLLEXPORT void set_desc(const IndexDescData* desc);

DLLEXPORT void add_and_update_record(const IndexRecordData* data);

DLLEXPORT void dummy();

#ifdef __cplusplus
}
#endif
