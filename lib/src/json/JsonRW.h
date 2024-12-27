/**
 * @file JsonRW.h
 * @brief Json読み書き
 * @author Satoshi Yamamoto
 * @date 2024/12/26
 * Copyright (C) 2024 Shoeisha Co., Ltd.
 */

#pragma once

#include "system/ConfigData.h"
#include "sakuinkunpp/IndexRecord.hpp"
#include "sakuinkunpp/IndexDesc.hpp"

#include <string>

namespace sakuin
{
extern bool loadConfig(ConfigData& config);
extern bool saveConfig(const ConfigData& config);

extern bool loadSakuin(const std::wstring& path, IndexDesc& desc, IndexRecordList& recordList);
extern bool saveSakuin(const std::wstring& path, const IndexDesc& desc, const IndexRecordList& recordList);

}