//
// Created by aleksei on 22.09.2020.
//

#include "Filter_BW.h"

void Filter_BW::filter_image(ImageZone& img_data) {
    for(int line = 0; line < img_data.get_height(); line++){
        for(int column = 0; column < img_data.get_width(); column++){
            pixel& curPixel = img_data.get_pixel(line, column);
            stbi_uc intensity = curPixel.colors[0] * 0.3 + curPixel.colors[1] * 0.6 + curPixel.colors[2] * 0.1;
            curPixel.colors[0] = curPixel.colors[1] = curPixel.colors[2] = intensity;
            img_data.set_pixel(line, column, curPixel);
        }
    }
}
