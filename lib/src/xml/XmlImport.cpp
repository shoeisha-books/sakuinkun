/**
 * @file XmlImport.cpp
 * @brief Xmlインポート用関数
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#include "XmlImport.h"
#include "util.h"
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <boost/locale.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/nowide/convert.hpp>

using namespace sakuin;
namespace
{
bool readFile(const std::wstring& fileName, std::string& buffer)
{
    std::filesystem::path path(fileName);
    if (!std::filesystem::exists(path))
    {
        return false;
    }
    
    std::ifstream ifs(path);
    
    std::stringstream ss;
    ss << ifs.rdbuf();

    buffer = ss.str();
    return true;
}

bool checkStr(const xmlChar* xmlCh, const std::string& str)
{
    return xmlStrcmp(xmlCh, BAD_CAST str.c_str()) == 0;
}

bool checkStr(const xmlChar* xmlCh, const std::wstring& wstr)
{
    return checkStr(xmlCh, boost::nowide::narrow(wstr));
}

struct AnnotationData
{
    int page = 0;
    std::wstring text;
};
using AnnotationList = std::vector<AnnotationData>;

AnnotationList calcAnnots(const xmlNodeSetPtr nodeset)
{
    AnnotationList ret;
    for (auto i = 0; i < nodeset->nodeNr; i++)
    {
        auto node = nodeset->nodeTab[i];
        AnnotationData data;
        for (auto attr = node->properties; attr; attr = attr->next)
        {
            if (checkStr(attr->name, L"page"))
            {
                if (attr->children)
                {
                    auto pageStr = (char*)attr->children->content;
                    data.page = boost::lexical_cast<int>(pageStr);
                }
            }
        }
        
        char* utfText = (char*)xmlXPathCastNodeToString(node);

        data.text = boost::nowide::widen(utfText);
        //data.text = boost::locale::conv::from_utf(utfText, "Shift_JIS");
        ret.push_back(data);
    }
    return ret;
}

AnnotationList parseXml(const std::string& buffer)
{
    auto doc = xmlReadMemory(buffer.c_str(), buffer.size(), "pdfcomment.xml", nullptr, 0);
    if (doc == nullptr)
    {
        // @TODO ERROR
        return AnnotationList();
    }
    auto context = xmlXPathNewContext(doc);
    if (context == nullptr)
    {
        // @TODO ERROR
        xmlFreeDoc(doc);
        return AnnotationList();
    }
    
    auto texts = xmlXPathEvalExpression(BAD_CAST "//*[local-name()='text' or local-name()='highlight']", context)->nodesetval;
    
    AnnotationList annots;
    annots.append_range(calcAnnots(texts));
    
    //std::cout << node->name << std::endl;
    xmlXPathFreeContext(context);
    xmlXPathFreeNodeSet(texts);
    //xmlXPathFreeNodeSet(highlights);
    xmlFreeDoc(doc);
    xmlCleanupParser();

    return annots;
}

XmlImportRecord createRecord(const AnnotationData& annot)
{
    std::vector<std::wstring> indexBuf;
    boost::algorithm::split(indexBuf, annot.text, boost::is_any_of(L"\r"));

    XmlImportRecord ret;

    ret.page = annot.page;

    std::wstring refStr;
    if (indexBuf.size() >= 2 && indexBuf[1].size() > 2)
    {
        // 参照指定ありの場合
        auto ref = indexBuf[1];
        switch (ref[0])
        {
        case L'-':
            ret.refType = ReferenceType::Range;
            break;
        case L'/':
            ret.refType = ReferenceType::See;
            break;
        case L'+':
            ret.refType = ReferenceType::SeeAlso;
            break;
        default:
            ret.refType = ReferenceType::Invalid;
            break;
        }
        refStr.assign(ref.begin() + 1, ref.end());
    }
    else
    {
        ret.refType = ReferenceType::Nombre;
    }
    
    switch (ret.refType)
    {
    case ReferenceType::Nombre:
        break;
    case ReferenceType::Range:
    case ReferenceType::See:
    case ReferenceType::SeeAlso:
        ret.referenceStr = refStr;
        break;
    default:
        break;
    }

    std::vector<std::wstring> wordBuf;
    boost::algorithm::replace_all(indexBuf[0], L"　", L"\t");
    boost::algorithm::split(wordBuf, indexBuf[0], boost::is_any_of(L"\t"));
    
    ret.keyWord = wordBuf[0];
    if (wordBuf.size() > 1)
    {
        ret.subKey = wordBuf[1];
    }


    return ret;
}
}

namespace sakuin
{
bool importXML(const std::wstring& fileName, XmlImportRecordList& records)
{
    // XFDFはUTF-8エンコード
    std::string buffer;
    if (!readFile(fileName, buffer))
    {
        return false;
    }

    auto annots = parseXml(buffer);
    records.clear();
    for (const auto& annot : annots)
    {
        records.push_back(createRecord(annot));
    }

    return true;

}

std::wstring getXml2Ver()
{
    return boost::nowide::widen(LIBXML_DOTTED_VERSION);
}
}
