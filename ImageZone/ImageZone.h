//
// Created by aleksei on 28.09.2020.
//

#ifndef STUDENT_TOOLKIT_IMAGEZONE_H
#define STUDENT_TOOLKIT_IMAGEZONE_H

#include "../png_toolkit.h"
#include "../stb_image.h"
#include "../ConfigReader/ConfigFilterReader.h"

struct pixel{
    stbi_uc colors[(int)STBI_rgb_alpha];
    int compPerPixel;
};

class ImageZone {
private:
    unsigned int left = 0;
    unsigned int right = 0;
    unsigned int up = 0;
    unsigned int bottom = 0;
    image_data imgData;
    pixel curPixel = {{0,0,0,0}, 0};
public:
    ImageZone(int up, int left,int bottom, int right, image_data& img);
    ImageZone(FilerParams& params, image_data& img);
    pixel& get_pixel(unsigned int row,unsigned int column);
    bool set_pixel(unsigned int row,unsigned  int column, pixel newPixel);
    unsigned int get_width() const;
    unsigned int get_height() const;

    ImageZone(FilerParams params, image_data data);
};


#endif //STUDENT_TOOLKIT_IMAGEZONE_H
