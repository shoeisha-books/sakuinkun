cmake_minimum_required(VERSION 3.28)

set(SrcFiles
    src/libsakuin.cpp
    src/IndexDesc.cpp
    src/IndexRecord.cpp
    src/Reference.cpp
    src/KeyWord.cpp
    src/SakuinKun.cpp
    src/system/ConfigData.h
    src/system/utf8_win.cpp
    src/mecab/MeCabCtrl.h
    src/mecab/MeCabCtrl.cpp
    src/xml/XmlImport.h
    src/xml/XmlImport.cpp
    src/json/JsonRW.h
    src/json/JsonRW.cpp
    src/xlsx/XlsxExport.h
    src/xlsx/XlsxExport.cpp
    src/util.h
    src/util.cpp)

if(MSVC)
  set(SrcFiles ${SrcFiles} manifest/libsakuin.manifest)
endif(MSVC)

set(HeaderFiles
    include/libsakuin.h
    include/sakuin_def.h
    include/sakuinkun/ReferenceType.h
    include/sakuinkunpp/IndexDesc.hpp
    include/sakuinkunpp/SakuinKun.hpp
    include/sakuinkunpp/IndexRecord.hpp
    include/sakuinkunpp/KeyWord.hpp
    include/sakuinkunpp/Reference.hpp)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SrcFiles})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HeaderFiles})


add_library(libsakuin SHARED ${SrcFiles} ${HeaderFiles})

find_package(mecab CONFIG REQUIRED)
target_link_libraries(libsakuin PRIVATE mecab::mecab)

add_dependencies(libsakuin xlsxwriter)
target_link_libraries(libsakuin PRIVATE xlsxwriter)

find_package(LibXml2 REQUIRED)
target_link_libraries(libsakuin PRIVATE LibXml2::LibXml2)

find_package(boost_uuid REQUIRED CONFIG)
target_link_libraries(libsakuin PRIVATE Boost::uuid)

find_package(boost_convert REQUIRED CONFIG)
target_link_libraries(libsakuin PRIVATE Boost::convert)

find_package(boost_locale REQUIRED CONFIG)
target_link_libraries(libsakuin PRIVATE Boost::locale)

find_package(boost_nowide REQUIRED CONFIG)
target_link_libraries(libsakuin PRIVATE Boost::nowide)

find_package(boost_algorithm REQUIRED CONFIG)
target_link_libraries(libsakuin PRIVATE Boost::algorithm)

#find_path(PICOJSON_INCLUDE_DIRS "picojson/picojson.h")
#target_include_directories(libsakuin PRIVATE ${PICOJSON_INCLUDE_DIRS})

target_include_directories(libsakuin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_dependencies(libsakuin mecab_data)

set(InstallDir ${CMAKE_CURRENT_SOURCE_DIR}/../_install)

add_custom_command(
    TARGET libsakuin
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "preparing install directory"
    COMMAND ${CMAKE_COMMAND} -E make_directory ${InstallDir}/$(ConfigurationName)
    COMMAND ${CMAKE_COMMAND} -E echo "Copying DLLs to install directory"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $(OutDir)iconv-2.dll $(OutDir)libsakuin.dll $(OutDir)libsakuin.lib $(OutDir)libxml2.dll $(OutDir)mecab.dll $(OutDir)minizip.dll $(OutDir)xlsxwriter.dll "$<IF:$<CONFIG:Debug>,$(OutDir)zlibd1.dll,$(OutDir)zlib1.dll>" ${InstallDir}/$(ConfigurationName)
    #COMMAND xcopy $(OutDir)\\* ${InstallDir}\\$(ConfiguratioName)
)
