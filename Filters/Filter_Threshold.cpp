//
// Created by aleksei on 06.10.2020.
//

#include <iostream>
#include "Filter_Threshold.h"

void Filter_Threshold::filter_image(ImageZone &img_data) {
    if (kern == nullptr) return;
    Filter_BW filterBw;
    filterBw.filter_image(img_data);
    for(unsigned int line = 0; line < img_data.get_height(); line++){
        for(unsigned int column = 0; column < img_data.get_width(); column++){
            int pixelInKern = 0;
            pixel& pixel = img_data.get_pixel(line,column);
            int yKern = - (int)(kernSize / 2);
            while (yKern <= (int)(kernSize / 2)){
                if(yKern + line >= 0 && yKern + line < img_data.get_height()) {
                    int xKern = - (int)(kernSize / 2);
                    while (xKern <= (int)kernSize / 2){
                        if(xKern + column >= 0 && xKern + column <img_data.get_width()){
                            kern[pixelInKern++] = img_data.get_pixel(line + yKern,column + xKern ).colors[0];
                        }
                        xKern++;
                    }
                }
                yKern++;
            }
            std::nth_element(kern, kern + pixelInKern/2, kern + pixelInKern);
            if(pixel.colors[0] < kern[pixelInKern/2]){
                pixel.colors[0] = pixel.colors[1] = pixel.colors[2] = 0;
                img_data.set_pixel(line, column, pixel);
            }
        }
    }


}

Filter_Threshold::Filter_Threshold() {
    kernSize = 5;
    kern = new stbi_uc[kernSize * kernSize];
}
