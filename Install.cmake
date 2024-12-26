cmake_minimum_required(VERSION 3.18)

message("INCLUDED!!!!")

set(InstallFiles_Release
    ${CMAKE_BINARY_DIR}/_bin/iconv-2.dll
    ${CMAKE_BINARY_DIR}/_bin/liblzma.dll
    ${CMAKE_BINARY_DIR}/_bin/libsakuin.dll
    ${CMAKE_BINARY_DIR}/_bin/libsakuin.exp
    ${CMAKE_BINARY_DIR}/_bin/libsakuin.lib
    ${CMAKE_BINARY_DIR}/_bin/libxml2.dll
    ${CMAKE_BINARY_DIR}/_bin/mecab.dll
    ${CMAKE_BINARY_DIR}/_bin/minizip.dll
    ${CMAKE_BINARY_DIR}/_bin/xlsxwriter.dll
    ${CMAKE_BINARY_DIR}/_bin/zlib1.dll
)
set(InstallFiles_Debug
    ${CMAKE_BINARY_DIR}/_bin/Debug/iconv-2.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/liblzma.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/libsakuin.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/libsakuin.exp
    ${CMAKE_BINARY_DIR}/_bin/Debug/libsakuin.lib
    ${CMAKE_BINARY_DIR}/_bin/Debug/libsakuin.pdb
    ${CMAKE_BINARY_DIR}/_bin/Debug/libxml2.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/mecab.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/minizip.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/xlsxwriter.dll
    ${CMAKE_BINARY_DIR}/_bin/Debug/zlibd1.dll
)

install(FILES ${InstallFiles_Release} CONFIGURATIONS Release
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/_install/Release)
install(FILES ${InstallFiles_Debug} CONFIGURATIONS Debug
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/_install/Debug)


set(DicDirs
    ${CMAKE_CURRENT_SOURCE_DIR}/mecab_data/dic
    ${CMAKE_CURRENT_SOURCE_DIR}/mecab_data/rc
)
install(DIRECTORY ${DicDirs} CONFIGURATIONS Release
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/_install/Release)
install(DIRECTORY ${DicDirs} CONFIGURATIONS Debug
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/_install/Debug)