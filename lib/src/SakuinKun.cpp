#include "sakuinkunpp/SakuinKun.hpp"
#include "mecab/MeCabCtrl.h"
#include "json/JsonRW.h"
#include "system/ConfigData.h"
#include "xlsx/XlsxExport.h"
#include "xml/XmlImport.h"
#include "sakuin_def.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <boost/nowide/convert.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <Windows.h>

using namespace sakuin;

SakuinKun& SakuinKun::getInstance()
{
    static SakuinKun inst;
    return inst;
}

/// VERSIONS
std::wstring SakuinKun::getLibVersion()
{
    return LibSakuinVer;
}
std::wstring SakuinKun::getMecabModelVersion()
{
    return MeCabCtrl::getModelVer();
}
std::wstring SakuinKun::getMecabTaggerVersion()
{
    return MeCabCtrl::getTaggerVer();
}
std::wstring SakuinKun::getBoostVersion()
{
    return boost::lexical_cast<std::wstring>(BOOST_VERSION);
}
std::wstring SakuinKun::getXml2Version()
{
    return ::getXml2Ver();
}
std::wstring SakuinKun::getXlsxWriterVersion()
{
    return ::getXlsxVer();
}


class SakuinKun::Impl
{
public:
    Impl();
    ~Impl();
    void initialize();
    bool isInitialized()const
    {
        return initialized_;
    }

    bool loadJson(const std::wstring& fileName);

    bool saveJson(const std::wstring& fileName)const;

    bool importXML(const std::wstring& fileName);

    bool exportXLSX(const std::wstring& fileName)const;

    void setDesc(const IndexDesc& desc)
    {
        desc_ = desc;
    }

    IndexDesc getDesc()const
    {
        return desc_;
    }

    const IndexRecordList& getRecordList()const
    {
        return indexRecords_;
    }

    bool getRecord(const std::wstring& uuid, IndexRecord& record);

    void addAndUpdateRecord(const IndexRecord& record);
private:
    KeyWord calcKeyWord(const std::wstring& word, const std::wstring& defaultYomi)const;
    IndexRecord calcIndexRecord(const XmlImportRecord& xml)const;
    bool restoreConfig();
    bool saveConfig()const;

    ConfigData config_ = {};
    MeCabCtrl mecab_;

    IndexDesc desc_;
    IndexRecordList indexRecords_;

    bool initialized_ = false;

};

SakuinKun::Impl::Impl()
    : desc_(IndexDesc(0, 0, true, L""))
{
    restoreConfig();
}

SakuinKun::Impl::~Impl()
{
    saveConfig();
}

bool SakuinKun::Impl::restoreConfig()
{
    ConfigData config;
    bool ret = loadConfig(config);
    if (ret)
    {
        config_ = config;
    }
    else
    {
        config_ = ConfigData::getDefault();
    }
    return ret;
}

bool SakuinKun::Impl::saveConfig()const
{
    return ::saveConfig(config_);
}

void SakuinKun::Impl::initialize()
{
    if (!initialized_)
    {
        // @TODO USER DIC
        mecab_.loadDic(config_.dic.systemDicPath);
        initialized_ = true;
    }
}

bool SakuinKun::Impl::loadJson(const std::wstring& fileName)
{
    return ::loadSakuin(fileName, desc_, indexRecords_);
}

bool SakuinKun::Impl::saveJson(const std::wstring& fileName)const
{
    return ::saveSakuin(fileName, desc_, indexRecords_);
}

bool SakuinKun::Impl::importXML(const std::wstring& fileName)
{
    indexRecords_.clear();
    XmlImportRecordList xmlRecords;
    if (!::importXML(fileName, xmlRecords))
    {
        return false;
    }

    for (const auto& xmlRecord : xmlRecords)
    {
        indexRecords_.push_back(calcIndexRecord(xmlRecord));
    }
    return true;
}

bool SakuinKun::Impl::exportXLSX(const std::wstring& fileName)const
{
    return ::exportXLSX(fileName, indexRecords_, desc_);
}

bool SakuinKun::Impl::getRecord(const std::wstring& uuid, IndexRecord& record)
{
    for (const auto& r : indexRecords_)
    {
        if (r.getId() == uuid)
        {
            record = r;
            return true;
        }
    }
    return false;
}

void SakuinKun::Impl::addAndUpdateRecord(const IndexRecord& record)
{
    // @TODO 各種チェック
    auto uuid = record.getId();

    for (auto& r : indexRecords_)
    {
        if (r.getId() == uuid)
        {
            r = record;
            return;
        }
    }
    indexRecords_.push_back(record);
}

KeyWord SakuinKun::Impl::calcKeyWord(const std::wstring& word, const std::wstring& defaultYomi)const
{
    std::wstring yomi = defaultYomi;
    if (word.empty())
    {
        yomi = L"";
    }
    else if (yomi.empty())
    {
        yomi = mecab_.calcYomi(word);
        if (yomi.empty())
        {
            yomi = word;
        }
    }
    return KeyWord(word, yomi);
}



IndexRecord SakuinKun::Impl::calcIndexRecord(const XmlImportRecord& xml)const
{
    auto mainKey = calcKeyWord(xml.keyWord, xml.keyDefaultYomi);
    auto subKey = calcKeyWord(xml.subKey, xml.subDefaultYomi);
    auto reference = Reference(xml.refType, xml.page, xml.referenceStr);

    return IndexRecord(mainKey, subKey, reference);
}

SakuinKun::SakuinKun()
    : impl_(new Impl())
{

}

SakuinKun::~SakuinKun()
{

}

void SakuinKun::initialize()
{
    impl_->initialize();
}

bool SakuinKun::isInitialized()const
{
    return impl_->isInitialized();
}

bool SakuinKun::loadJson(const std::wstring& fileName)
{
    return impl_->loadJson(fileName);
}

bool SakuinKun::saveJson(const std::wstring& fileName)const
{
    return impl_->saveJson(fileName);
}

bool SakuinKun::importXML(const std::wstring& fileName)
{
    return impl_->importXML(fileName);
}

bool SakuinKun::exportXLSX(const std::wstring& fileName)const
{
    return impl_->exportXLSX(fileName);
}

void SakuinKun::setDesc(const IndexDesc& desc)
{
    impl_->setDesc(desc);
}

IndexDesc SakuinKun::getDesc()const
{
    return impl_->getDesc();
}

bool SakuinKun::getRecord(const std::wstring& uuid, IndexRecord& record)const
{
    return impl_->getRecord(uuid, record);
}

void SakuinKun::addAndUpdateRecord(const IndexRecord& record)
{
    impl_->addAndUpdateRecord(record);
}

IndexRecordList SakuinKun::getRecordList()const
{
    return impl_->getRecordList();
}
