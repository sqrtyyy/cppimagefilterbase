//
// Created by aleksei on 22.09.2020.
//

#include "Filter_BW.h"


void Filter_BW::filter_image(ImageZone& img_data) {
    if(img_data.isEmpty()) return;
    for(int line = 0; line < img_data.get_height(); line++){
        for(int column = 0; column < img_data.get_width(); column++){
            pixel& curPixel = img_data.get_pixel(line, column);
            curPixel.colors[0] = curPixel.colors[1] = curPixel.colors[2] = intensity(curPixel);
            img_data.set_pixel(line, column, curPixel);
        }
    }
}
