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
add_subdirectory(cli_app)
add_subdirectory(cli_app_cpp)
add_subdirectory(mecab_data)

include_external_msproject(SakuinKun ${CMAKE_CURRENT_SOURCE_DIR}/guiapp_csharp/SakuinKun.csproj)
add_dependencies(libsakuin extlib mecab_data)
add_dependencies(SakuinKun libsakuin)
add_dependencies(sakuin-cli-cpp libsakuin)
add_dependencies(sakuin-cli libsakuin)
include(Install.cmake)
