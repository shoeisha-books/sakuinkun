cmake_minimum_required(VERSION 3.28)

set(SrcFiles
    src/main.cpp
)

if(MSVC)
  set(SrcFiles ${SrcFiles} manifest/sakuin.manifest)
endif(MSVC)

add_executable(sakuin-cli ${SrcFiles})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SrcFiles})

add_dependencies(sakuin-cli libsakuin)
target_link_libraries(sakuin-cli PUBLIC libsakuin)
