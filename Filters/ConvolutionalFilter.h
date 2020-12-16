//
// Created by aleksei on 08.12.2020.
//

#ifndef STUDENT_TOOLKIT_CONVOLUTIONALFILTER_H
#define STUDENT_TOOLKIT_CONVOLUTIONALFILTER_H
#include "KernFilter.h"
#include "../ImageZone/ImageZone.h"
class ConvolutionalFilter : public KernFilter {
public:
    void convolute(ImageZone& img_data);

private:
    int weightSum();
};


#endif //STUDENT_TOOLKIT_CONVOLUTIONALFILTER_H
