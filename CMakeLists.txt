cmake_minimum_required(VERSION 2.8)


project(student_toolkit)
file(GLOB FILTERS_SRC Filters/*.cpp Filters/*.h)
file(GLOB CFG_READER_SRC ConfigReader/*.cpp ConfigReader/*.h)
file(GLOB ImageZoneSRC ImageZone/*.cpp ImageZone/*.h)



add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" ${FILTERS_SRC} ${CFG_READER_SRC} ${ImageZoneSRC})