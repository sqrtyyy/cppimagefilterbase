//
// Created by aleksei on 08.12.2020.
//

#ifndef STUDENT_TOOLKIT_FILTER_BLUR_H
#define STUDENT_TOOLKIT_FILTER_BLUR_H
#include "ConvolutionalFilter.h"

class Filter_Blur : public ConvolutionalFilter {
public:
    Filter_Blur();
    void filter_image(ImageZone& img_data) override;
};


#endif //STUDENT_TOOLKIT_FILTER_BLUR_H
