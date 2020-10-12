cmake_minimum_required(VERSION 2.8)


project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" Filters/Filter.cpp Filters/Filter.h
        Filters/Filter_BW.cpp Filters/Filter_BW.h Filters/Filter_Red.cpp Filters/Filter_Red.h Filters/FilterFabric.cpp
        Filters/FilterFabric.h ConfigReader/ConfigFilterReader.cpp ConfigReader/ConfigFilterReader.h ImageZone/ImageZone.cpp ImageZone/ImageZone.h Filters/Filter_Threshold.cpp Filters/Filter_Threshold.h Filters/KernFilter.cpp Filters/KernFilter.h)
