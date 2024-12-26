cmake_minimum_required(VERSION 3.28)

#VC Unicode対応
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(CMAKE_CXX_STANDARD 23)

#仮置き
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/_bin/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/_bin/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/_bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/_bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/_bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/_bin)

set(VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/mecab_data)


project(sakuinkun)

add_subdirectory(extlibs)
add_subdirectory(lib)
add_subdirectory(app)
#add_subdirectory(guiapp)
add_subdirectory(mecab_data)

include(Install.cmake)
