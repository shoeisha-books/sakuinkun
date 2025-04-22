cmake_minimum_required(VERSION 3.18)

set(DicFiles
    dic/char.bin
    dic/dicrc
    dic/matrix.bin
    dic/sys.dic
    dic/unk.dic
)

add_custom_target(mecab_data
    SOURCES ${DicFiles}
)

file(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}\\..\\ PrjRootDir)

add_custom_command(
    TARGET mecab_data
    POST_BUILD
    COMMAND xcopy ${PrjRootDir}\\mecab_data\\dic ${PrjRootDir}\\_install\\$(ConfigurationName)\\dic\\ /E /I /Y
    COMMAND xcopy ${PrjRootDir}\\mecab_data\\rc ${PrjRootDir}\\_install\\$(ConfigurationName)\\rc\\ /E /I /Y
)
