#include "json/JsonRW.h"
#include "sakuinkunpp/IndexDesc.hpp"
#include "sakuin_def.h"

#include <picojson/picojson.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/nowide/convert.hpp>
#include <boost/lexical_cast.hpp>

#include "system/ConfigData.h"

using namespace sakuin;
namespace
{
constexpr bool Prettify = true;

bool loadJson(const std::wstring& fileName, picojson::value& json)
{
    auto path = std::filesystem::path(fileName);
    if(!std::filesystem::exists(path))
    {
        return false;
    }
    auto ifs = std::ifstream(path);
    auto ss = std::stringstream();
    ss << ifs.rdbuf();

    auto buffer = ss.str();
    auto jVal = picojson::value();
    auto err = picojson::parse(jVal, buffer);
    if (!err.empty())
    {
        std::cerr << "[JSON err]: " << err << std::endl;
        return false;
    }

    json = jVal;
    return true;
}

bool saveJson(const std::wstring& fileName, const picojson::value& json)
{
    auto buffer = json.serialize(Prettify);
    auto path = std::filesystem::path(fileName);
    auto ofs = std::ofstream(path);

    if (!ofs)
    {
        return false;
    }

    ofs << buffer;

    return true;
}

picojson::value convToJson(const VersionData& ver)
{
    auto ret = picojson::object();
    ret.insert(std::pair("majorVer", static_cast<double>(ver.majorVer)));
    ret.insert(std::pair("minorVer", static_cast<double>(ver.minorVer)));
    ret.insert(std::pair("patchVer", static_cast<double>(ver.patchVer)));

    return picojson::value(ret);
}

picojson::value convToJson(const UserDicConfigData& userDic)
{
    auto ret = picojson::object();
    ret.insert(std::pair("path", boost::nowide::narrow(userDic.path)));
    ret.insert(std::pair("summary", boost::nowide::narrow(userDic.summary)));
    return picojson::value(ret);
}

picojson::value convToJson(const DicConfigData& dic)
{
    auto ret = picojson::object();
    ret.insert(std::pair("systemDicPath", boost::nowide::narrow(dic.systemDicPath)));

    auto userDics = picojson::array();
    for (const auto& user : dic.userDics)
    {
        userDics.push_back(convToJson(user));
    }
    ret.insert(std::pair("userDics", userDics));
    return picojson::value(ret);
}

picojson::value convToJson(const LastData& last)
{
    auto ret = picojson::object();
    ret.insert(std::pair("workingPath", boost::nowide::narrow(last.workingPath)));
    return picojson::value(ret);
}

picojson::value convToJson(const ConfigData& config)
{
    auto ret = picojson::object();
    ret.insert(std::pair("version", convToJson(config.version)));
    ret.insert(std::pair("dic", convToJson(config.dic)));
    ret.insert(std::pair("last", convToJson(config.last)));
    return picojson::value(ret);
}

picojson::value convToJson(const KeyWord& keyWord)
{
    auto ret = picojson::object();
    ret.insert(std::pair("word", boost::nowide::narrow(keyWord.getWord())));
    ret.insert(std::pair("yomi", boost::nowide::narrow(keyWord.getYomi())));
    return picojson::value(ret);
}

picojson::value convToJson(const Reference& reference)
{
    auto typeToInt = [](ReferenceType type)->double
        {
            switch (type)
            {
            case ReferenceType::Nombre:
                return 0;
            case ReferenceType::Range:
                return 1;
            case ReferenceType::See:
                return 2;
            case ReferenceType::SeeAlso:
                return 3;
            default:
                return -1;
            }
        };

    auto ret = picojson::object();
    ret.insert(std::pair("type", typeToInt(reference.getType())));
    ret.insert(std::pair("page", static_cast<double>(reference.getPage())));
    ret.insert(std::pair("refStr", boost::nowide::narrow(reference.getRefStr())));

    return picojson::value(ret);
}

picojson::value convToJson(const IndexRecord& record)
{
    auto ret = picojson::object();
    ret.insert(std::pair("id", boost::nowide::narrow(record.getId())));
    ret.insert(std::pair("mainKey", convToJson(record.getMainKey())));
    ret.insert(std::pair("subKey", convToJson(record.getSubKey())));
    ret.insert(std::pair("ref", convToJson(record.getReference())));
    return picojson::value(ret);
}

picojson::value convToJson(const IndexDesc& desc)
{
    auto ret = picojson::object();
    ret.insert(std::pair("offset", static_cast<double>(desc.getOffset())));
    ret.insert(std::pair("romanPageNum", static_cast<double>(desc.getRomanPageNum())));
    ret.insert(std::pair("romanCap", static_cast<bool>(desc.isRomanCap())));
    ret.insert(std::pair("repeat", boost::nowide::narrow(desc.getRepeat())));
    return picojson::value(ret);
}

picojson::value convToJson(const IndexRecordList& recordList)
{
    auto arr = picojson::array();
    for (auto record : recordList)
    {
        arr.push_back(convToJson(record));
    }
    return picojson::value(arr);
}

bool parseVersion(const picojson::value& json, VersionData& version)
{
    if (!json.contains("majorVer") || !json.contains("minorVer") || !json.contains("patchVer"))
    {
        return false;
    }

    version.majorVer = json.get("majorVer").get<double>();
    version.minorVer = json.get("minorVer").get<double>();
    version.patchVer = json.get("patchVer").get<double>();

    return true;
}

bool parseUserDic(const picojson::value& json, UserDicConfigData& userDic)
{
    if (!json.contains("path") || !json.contains("summary"))
    {
        return false;
    }

    userDic.path = boost::nowide::widen(json.get("path").get<std::string>());
    userDic.summary = boost::nowide::widen(json.get("summary").get<std::string>());

    return true;
}

bool parseDic(const picojson::value& json, DicConfigData& dic)
{
    if (!json.contains("systemDicPath") || !json.contains("userDics"))
    {
        return false;
    }

    dic.systemDicPath = boost::nowide::widen(json.get("systemDicPath").get<std::string>());
    dic.userDics.clear();
    auto userDics = json.get("userDics").get<picojson::array>();
    for (auto userDic : userDics)
    {
        auto userDicConf = UserDicConfigData();
        if (parseUserDic(userDic, userDicConf))
        {
            dic.userDics.push_back(userDicConf);
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool parseLast(const picojson::value& json, LastData& last)
{
    if (!json.contains("workingPath"))
    {
        return false;
    }
    last.workingPath = boost::nowide::widen(json.get("workingPath").get<std::string>());
    return true;
}

bool parseConfig(const picojson::value& json, ConfigData& config)
{
    ConfigData ret;
    if (!json.contains("version") || !json.contains("dic") || !json.contains("last"))
    {
        return false;
    }
    if (!parseVersion(json.get("version"), ret.version))
    {
        return false;
    }
    if (!parseDic(json.get("dic"), ret.dic))
    {
        return false;
    }
    if (!parseLast(json.get("last"), ret.last))
    {
        return false;
    }

    config = ret;
    return true;
}

bool parseKeyWordData(const picojson::value& json, std::shared_ptr<KeyWord>& keyWordPtr)
{
    if (!json.contains("word") || !json.contains("yomi"))
    {
        return false;
    }

    std::wstring wordBuf = boost::nowide::widen(json.get("word").get<std::string>());
    std::wstring yomiBuf = boost::nowide::widen(json.get("yomi").get<std::string>());

    keyWordPtr = std::shared_ptr<KeyWord>(new KeyWord(wordBuf, yomiBuf));

    return true;
}

bool parseReferenceData(const picojson::value& json, std::shared_ptr<Reference>& refPtr)
{
    if (!json.contains("type") || !json.contains("page") || !json.contains("refStr"))
    {
        return false;
    }

    ReferenceType type;
    int typeInt = json.get("type").get<double>();
    switch (typeInt)
    {
    case 0:
        type = ReferenceType::Nombre;
        break;
    case 1:
        type = ReferenceType::Range;
        break;
    case 2:
        type = ReferenceType::See;
        break;
    case 3:
        type = ReferenceType::SeeAlso;
        break;
    default:
        type = ReferenceType::Invalid;
        break;
    }

    int page = json.get("page").get<double>();

    std::wstring refStr = boost::nowide::widen(json.get("refStr").get<std::string>());

    refPtr = std::shared_ptr<Reference>(new Reference(type, page, refStr));

    return true;
}

bool parseIndexRecord(const picojson::value& json, std::shared_ptr<IndexRecord>& indexRecordPtr)
{
    std::shared_ptr<IndexRecord> ret;
    std::cout << json.serialize(true) << std::endl;
    if (!json.contains("id") || !json.contains("mainKey") || !json.contains("subKey") || !json.contains("ref"))
    {
        return false;
    }

    std::wstring idBuf = boost::nowide::widen(json.get("id").get<std::string>());

    bool mainKeyValidFlag = false;
    std::shared_ptr<KeyWord> mainKeyPtr;
    if (!parseKeyWordData(json.get("mainKey"), mainKeyPtr))
    {
        return false;
    }

    std::shared_ptr<KeyWord> subKeyPtr;
    if (!parseKeyWordData(json.get("subKey"), subKeyPtr))
    {
        return false;
    }

    std::shared_ptr<Reference> refPtr;
    if (!parseReferenceData(json.get("ref"), refPtr));

    indexRecordPtr = std::shared_ptr<IndexRecord>(new IndexRecord(*mainKeyPtr, *subKeyPtr, *refPtr, idBuf));

    return true;
}

bool parseIndexRecordList(const picojson::value& json, IndexRecordList& indexRecordList)
{
    picojson::array jArr = json.get<picojson::array>();

    for (auto indexRecordJson : jArr)
    {
        bool res = false;
        std::shared_ptr<IndexRecord> dataPtr;
        if (parseIndexRecord(indexRecordJson, dataPtr))
        {
            indexRecordList.push_back(*dataPtr);
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool parseIndexHeader(const picojson::value& json, std::shared_ptr<IndexDesc>& desc)
{
    if (!json.contains("offset") || !json.contains("romanPageNum") || !json.contains("romanCap") || !json.contains("repeat"))
    {
        return false;
    }

    int offset = json.get("offset").get<double>();
    int romanPageNum = json.get("romanPageNum").get<double>();
    bool romanCap = json.get("romanCap").get<bool>();
    std::wstring repeat = boost::nowide::widen(json.get("repeat").get<std::string>());

    desc = std::shared_ptr<IndexDesc>(new IndexDesc(offset, romanPageNum, romanCap, repeat));

    return true;
}

const wchar_t* ConfigPath = L"./config.json";

}

namespace sakuin
{

bool saveConfig(const ConfigData& config)
{
    auto json = convToJson(config);
    return saveJson(ConfigPath, json);
}

bool loadConfig(ConfigData& config)
{
    auto json = picojson::value();
    if (!loadJson(ConfigPath, json))
    {
        return false;
    }
    return parseConfig(json, config);
}

bool loadSakuin(const std::wstring& path, IndexDesc& desc, IndexRecordList& recordList)
{
    recordList.clear();
    auto json = picojson::value();
    if (!loadJson(path, json))
    {
        return false;
    }
    std::shared_ptr<IndexDesc> descPtr;
    if (!parseIndexHeader(json.get("header"), descPtr))
    {
        return false;
    }
    desc = *descPtr;
    return parseIndexRecordList(json.get("list"), recordList);
}

bool saveSakuin(const std::wstring& path, const IndexDesc& desc, const IndexRecordList& recordList)
{
    auto headerJson = convToJson(desc);
    auto listJson = convToJson(recordList);
    auto json = picojson::object();
    json.insert(std::pair("header", headerJson));
    json.insert(std::pair("list", listJson));
    return saveJson(path, picojson::value(json));
}

}