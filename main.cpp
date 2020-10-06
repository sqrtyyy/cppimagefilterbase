#include <iostream>
#include "png_toolkit.h"
#include "Filters/Filter_BW.h"
#include "ConfigReader/ConfigFilterReader.h"
#include "Filters/FilterFabric.h"
int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test.png images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";
        png_toolkit studTool;
        if(studTool.load(argv[2])){
            FilerParams params = ConfigFilterReader::parseFile(argv[1]);
            Filter* filterBw = FilterFabric::createFilter(params);
            ImageZone zone = ImageZone(params, studTool.getPixelData());
            filterBw->filter_image(zone);
            studTool.save(argv[3]);
            }

    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
