/**
 * @file XlsxExport.h
 * @brief XLSXエクスポート用関数
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once
#include <string>
#include "sakuinkunpp/IndexRecord.hpp"
#include "sakuinkunpp/IndexDesc.hpp"

namespace sakuin
{
extern bool exportXLSX(const std::wstring& fileName, const IndexRecordList& recordList, const IndexDesc& desc);

extern std::wstring getXlsxVer();
}
