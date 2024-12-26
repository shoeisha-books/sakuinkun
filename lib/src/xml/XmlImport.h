#pragma once

#include <string>
#include <vector>
#include "sakuinkun/ReferenceType.h"

namespace sakuin
{

struct XmlImportRecord
{
    std::wstring keyWord;
    std::wstring keyDefaultYomi;
    std::wstring subKey;
    std::wstring subDefaultYomi;
    int page;
    ReferenceType refType = ReferenceType::Nombre;
    std::wstring referenceStr;
};

using XmlImportRecordList = std::vector<XmlImportRecord>;

extern bool importXML(const std::wstring& fileName, XmlImportRecordList& records);

extern std::wstring getXml2Ver();
}
