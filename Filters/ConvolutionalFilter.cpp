//
// Created by aleksei on 08.12.2020.
//

#include "ConvolutionalFilter.h"

void ConvolutionalFilter::convolute(ImageZone &img_data) {
    for(unsigned int line = 0; line < img_data.get_height(); line++){
        for(unsigned int column = 0; column < img_data.get_width(); column++){
            pixel pixel_ = {{0, 0, 0}, 3};
            size_t idx = 0;
            for (int yKern = - (int)(kernSize / 2); yKern <= (int)(kernSize / 2); yKern++) {
                if(yKern + line < 0 || yKern + line >= img_data.get_height()) {
                    idx += kernSize;
                    continue;
                }
                for (int xKern = - (int)(kernSize / 2); xKern <= (int)kernSize / 2; xKern++){
                    if(xKern + column >= 0 && xKern + column <img_data.get_width()){
                        if(xKern + column >= 0 && xKern + column <img_data.get_width()){
                            int weight = kern[idx];

                            auto pixel = img_data.get_pixel(line + yKern,column + xKern);
                            for (int i = 0; i < 3; ++i) {
                                pixel_.colors[i] += weight * pixel.colors[i];
                            }
                        }
                       idx++;
                    }
                }
            }

            for (int i = 0; i < 3; ++i) {
                pixel_.colors[i] /= weightSum();
            }

            img_data.set_pixel(line, column, pixel_);
        }
    }
}

int ConvolutionalFilter::weightSum() {
    int sum = 0;
    for (const auto &item : kern) {
        sum += item;
    }
    return sum;
}
