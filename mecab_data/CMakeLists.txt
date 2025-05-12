cmake_minimum_required(VERSION 3.18)

set(DicFiles
    dic/char.bin
    dic/dicrc
    dic/matrix.bin
    dic/sys.dic
    dic/unk.dic
)

set(RcFiles
    rc/mecabrc)

set(InstallDir ${CMAKE_CURRENT_SOURCE_DIR}/../_install)

add_custom_target(mecab_data
    COMMAND ${CMAKE_COMMAND} -E make_directory ${InstallDir}/$(ConfigurationName)/dic
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${DicFiles} ${InstallDir}/$(ConfigurationName)/dic
    COMMAND ${CMAKE_COMMAND} -E make_directory ${InstallDir}/$(ConfigurationName)/rc
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RcFiles} ${InstallDir}/$(ConfigurationName)/rc
    SOURCES ${DicFiles} ${RcFiles}
)
