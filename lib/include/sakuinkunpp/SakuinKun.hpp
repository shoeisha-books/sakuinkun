/**
 * @file SakuinKun.hpp
 * @brief さくいんくん本体クラス
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once
#include "sakuin_def.h"

#include "IndexDesc.hpp"
#include "KeyWord.hpp"
#include "Reference.hpp"
#include "IndexRecord.hpp"

#include <string>
#include <memory>
#include <vector>

// 前方宣言
struct IndexData;

namespace sakuin
{
/// <summary>
/// さくいん君メインクラス
/// </summary>
class DLLEXPORT SakuinKun
{
private:
    // 呼び出し不可。インスタンスはgetInstance()で取得
    SakuinKun();
public:
    ~SakuinKun();

public:
    /// <summary>
    /// シングルトンインスタンス取得
    /// </summary>
    /// <returns></returns>
    static SakuinKun& getInstance();

    /// <summary>
    /// 初期化
    /// </summary>
    void initialize();

    /// <summary>
    /// 初期化済みか
    /// </summary>
    /// <returns></returns>
    bool isInitialized()const;

    /// <summary>
    /// 終了処理
    /// </summary>
    void terminate();

    /// <summary>
    /// JSONファイルのロード
    /// </summary>
    /// <param name="fileName"></param>
    bool loadJson(const std::wstring& fileName);

    /// <summary>
    /// JSONファイルへの保存
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    bool saveJson(const std::wstring& fileName)const;

    /// <summary>
    /// XMLからのインポート
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    bool importXML(const std::wstring& fileName);

    /// <summary>
    /// XLSXへのエクスポート
    /// </summary>
    /// <param name="fileName"></param>
    /// <returns></returns>
    bool exportXLSX(const std::wstring& fileName)const;

    /// <summary>
    /// 設定をセット
    /// </summary>
    /// <param name="desc"></param>
    void setDesc(const IndexDesc& desc);

    /// <summary>
    /// 設定の取得
    /// </summary>
    /// <returns></returns>
    IndexDesc getDesc()const;

    /// <summary>
    /// 保存リスト上のレコード取得
    /// </summary>
    /// <param name="uuid"></param>
    /// <param name="record"></param>
    /// <returns></returns>
    bool getRecord(const std::wstring& uuid, IndexRecord& record)const;

    /// <summary>
    /// 保存リスト取得
    /// </summary>
    /// <returns></returns>
    IndexRecordList getRecordList()const;

    /// <summary>
    /// レコードの追加・更新
    /// </summary>
    /// <param name="record">追加・更新するレコード</param>
    void addAndUpdateRecord(const IndexRecord& record);

    /// <summary>
    /// レコードの削除
    /// </summary>
    /// <param name="uuid"></param>
    void removeRecord(const std::wstring& uuid);


    /// <summary>
    /// ライブラリバージョン取得
    /// </summary>
    /// <returns></returns>
    static std::wstring getLibVersion();

    /// <summary>
    /// MeCab::Modelのバージョン取得
    /// </summary>
    /// <returns></returns>
    static std::wstring getMecabModelVersion();

    /// <summary>
    /// MeCab::Taggerのバージョン取得
    /// </summary>
    /// <returns></returns>
    static std::wstring getMecabTaggerVersion();

    /// <summary>
    /// Boostのバージョン取得
    /// </summary>
    /// <returns></returns>
    static std::wstring getBoostVersion();

    /// <summary>
    /// Xml2のバージョン取得
    /// </summary>
    /// <returns></returns>
    static std::wstring getXml2Version();

    /// <summary>
    /// XlsxWriterのバージョン取得
    /// </summary>
    /// <returns></returns>
    static std::wstring getXlsxWriterVersion();

private:
    // pimpl
    class Impl;
    std::shared_ptr<Impl> impl_;
};
}
