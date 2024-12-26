#pragma once

#include "IndexDesc.hpp"
#include "KeyWord.hpp"
#include "Reference.hpp"
#include "IndexRecord.hpp"

#include <string>
#include <memory>
#include <vector>

struct IndexData;

namespace sakuin
{
/// @brief さくいん君メインクラス。設定ファイルは「./config.json」
class SakuinKun
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
    /// JSONファイルのロード
    /// </summary>
    /// <param name="fileName"></param>
    bool loadJson(const std::wstring& fileName);

    /// @brief JSONファイルへの保存
    /// @param fileName 
    bool saveJson(const std::wstring& fileName)const;

    /// @brief XMLからのインポート
    /// @param fileName 
    bool importXML(const std::wstring& fileName);

    /// @brief XLSXへのエクスポート
    /// @param fileName 
    bool exportXLSX(const std::wstring& fileName)const;

    /// <summary>
    /// 設定をセット
    /// </summary>
    /// <param name="desc"></param>
    void setDesc(const IndexDesc& desc);

    IndexDesc getDesc()const;

    /// @brief 保存リスト上のレコード取得
    /// @param id
    /// @return 
    bool getRecord(const std::wstring& uuid, IndexRecord& record)const;

    /// @brief 保存リスト取得
    /// @return 
    IndexRecordList getRecordList()const;

    /// @brief レコードの追加・更新
    /// @param record 追加・更新するレコード
    void addAndUpdateRecord(const IndexRecord& record);

    /// @brief レコードの削除
    /// @param id 
    void removeRecord(const std::wstring& uuid);


    static std::wstring getLibVersion();
    static std::wstring getMecabModelVersion();
    static std::wstring getMecabTaggerVersion();
    static std::wstring getBoostVersion();
    static std::wstring getXml2Version();
    static std::wstring getXlsxWriterVersion();


private:
    class Impl;
    std::shared_ptr<Impl> impl_;
};
}
