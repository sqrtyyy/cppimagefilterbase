//
// Created by aleksei on 06.10.2020.
//

#include <vector>
#include "Filter_Threshold.h"

void Filter_Threshold::filter_image(ImageZone &img_data) {
    if (kern.empty()) return;
    Filter_BW filterBw;
    filterBw.filter_image(img_data);
    vector<std::pair<unsigned int,unsigned int>> blacked = {};
    for(unsigned int line = 0; line < img_data.get_height(); line++){
        for(unsigned int column = 0; column < img_data.get_width(); column++){
            int pixelInKern = 0;
            for (int yKern = - (int)(kernSize / 2); yKern <= (int)(kernSize / 2); yKern++) {
                if(yKern + line < 0 || yKern + line >= img_data.get_height()) continue;
                for (int xKern = - (int)(kernSize / 2); xKern <= (int)kernSize / 2; xKern++){
                    if(xKern + column >= 0 && xKern + column <img_data.get_width()){
                        kern[pixelInKern++] = img_data.get_pixel(line + yKern,column + xKern).colors[0];
                    }
                }
            }

            std::nth_element(kern.begin(), kern.begin() + pixelInKern / 2, kern.begin() + pixelInKern);
            if(img_data.get_pixel(line, column).colors[0] < kern[pixelInKern / 2]){
               blacked.emplace_back(line, column);
            }
        }
    }
    pixel blackPixel = {{0, 0, 0}, 3};
    for(auto & coord : blacked){
        img_data.set_pixel(coord.first, coord.second, blackPixel);
    }
}

Filter_Threshold::Filter_Threshold() {
    kernSize = 5;
    kern.resize(kernSize * kernSize);
}
