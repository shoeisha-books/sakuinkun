#pragma once
#include <string>
#include "sakuinkunpp/IndexRecord.hpp"
#include "sakuinkunpp/IndexDesc.hpp"

namespace sakuin
{
extern bool exportXLSX(const std::wstring& fileName, const IndexRecordList& recordList, const IndexDesc& desc);

extern std::wstring getXlsxVer();
}
