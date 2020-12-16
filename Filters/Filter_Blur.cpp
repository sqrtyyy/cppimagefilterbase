//
// Created by aleksei on 08.12.2020.
//

#include "Filter_Blur.h"

Filter_Blur::Filter_Blur() {
    kernSize = 3;
    kern = std::vector<int>(1, kernSize * kernSize);
}

void Filter_Blur::filter_image(ImageZone &img_data) {
    ConvolutionalFilter::convolute(img_data);
}
