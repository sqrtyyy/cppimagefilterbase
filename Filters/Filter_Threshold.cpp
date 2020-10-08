//
// Created by aleksei on 06.10.2020.
//

#include <vector>
#include <iostream>
#include "Filter_Threshold.h"

void Filter_Threshold::filter_image(ImageZone &img_data) {
    if (kern.empty()) return;
    Filter_BW filterBw;
    filterBw.filter_image(img_data);
    unsigned int pixelsInKernLine = img_data.get_width() * kernSize;
    unsigned int zeroPixelAbscissa[pixelsInKernLine * 2];
    unsigned int zeroPixelOrdinate[pixelsInKernLine * 2];
    unsigned int zeroNum1 = 0;
    unsigned int zeroNum2 = 0;
    vector<vector<int>> zeroed(2);
    for(unsigned int line = 0; line < img_data.get_height(); line++){
        if((line + 1) % 5 == 0){
            unsigned int zeroNum;
            unsigned int part;
            if((line + 1) / 5 % 2 == 0){
                zeroNum = zeroNum2;
                part = 1;
                zeroNum2 = 0;
            } else {
                zeroNum = zeroNum1;
                part = 0;
                zeroNum1 = 0;
            }
            part *= pixelsInKernLine;
            pixel nullPixel = {{255,0,}, 3};
            for(unsigned int i = 0; i < zeroNum; i++){
        //        img_data.set_pixel( zeroPixelOrdinate[i + part], zeroPixelAbscissa[i + part], nullPixel);
            }
        }
        for(unsigned int column = 0; column < img_data.get_width(); column++){
            int pixelInKern = 0;
            pixel& pixel = img_data.get_pixel(line,column);
            for (int yKern = - (int)(kernSize / 2); yKern <= (int)(kernSize / 2); yKern++) {
                if(yKern + line < 0 || yKern + line >= img_data.get_height()) continue;
                for (int xKern = - (int)(kernSize / 2); xKern <= (int)kernSize / 2; xKern++){
                    if(xKern + column >= 0 && xKern + column <img_data.get_width()){
                        kern[pixelInKern++] = img_data.get_pixel(line + yKern,column + xKern).colors[0];
                    }
                }
            }
            std::nth_element(kern.begin(), kern.begin() + pixelInKern / 2, kern.begin() + pixelInKern);
            if(pixel.colors[0] < kern[pixelInKern / 2]){
                unsigned int zeroNum;
                unsigned int part;
                if(((line + 1) / 5) % 2 == 1){
                    zeroNum = zeroNum2;
                    part = 1;
                    zeroNum2++;
                } else {
                    zeroNum = zeroNum1;
                    part = 0;
                    zeroNum1++;
                }
              //  img_data.set_pixel(line, column, {{0,0,0},3});
                zeroed[0].push_back(line);
                zeroed[1].push_back(column);
                zeroPixelAbscissa[zeroNum + part * pixelsInKernLine] = column;
                zeroPixelOrdinate[zeroNum + part * pixelsInKernLine] = line;
            }
        }
        for (int i = 0; i < zeroed[0].size(); ++i) {
            img_data.set_pixel(zeroed[0][i],zeroed[1][i],{{0,0,0},3});
        }
    }


}

Filter_Threshold::Filter_Threshold() {
    kernSize = 5;
    kern.resize(kernSize * kernSize);
}
