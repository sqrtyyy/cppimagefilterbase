#include <iostream>
#include "png_toolkit.h"
#include "ConfigReader/ConfigFilterReader.h"
#include "Filters/FilterFabric.h"
int main( int argc, char *argv[] )
{
    try
    {
        if (argc != 4)
            throw "Not enough arguments";
        png_toolkit studTool;
        if(studTool.load(argv[2])){
            ConfigFilterReader reader(argv[1]);
            FilerParams params = reader.nextFilter();

                Filter *filter = FilterFabric::createFilter(params);
                ImageZone zone = ImageZone(params, studTool.getPixelData());
                filter->filter_image(zone);
            studTool.save(argv[3]);
            delete filter;
        }
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
