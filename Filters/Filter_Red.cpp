//
// Created by aleksei on 22.09.2020.
//

#include "Filter_Red.h"

void Filter_Red::filter_image(ImageZone& img_data) {
    for (int line = 0; line < img_data.get_height(); line++){
        for (int column = 0; column < img_data.get_width(); column++){
            pixel& curPixel = img_data.get_pixel(line, column);
            curPixel.colors[0] = 255;
            curPixel.colors[1] = curPixel.colors[2] = 0;
            img_data.set_pixel(line, column, curPixel);
        }
    }
}

