//
// Created by aleksei on 06.10.2020.
//

#ifndef STUDENT_TOOLKIT_FILTER_THRESHOLD_H
#define STUDENT_TOOLKIT_FILTER_THRESHOLD_H

#include "Filter_BW.h"
#include "KernFilter.h"
#include <algorithm>

class Filter_Threshold : public KernFilter{
public:
    Filter_Threshold();
    void filter_image(ImageZone& img_data) override;
};


#endif //STUDENT_TOOLKIT_FILTER_THRESHOLD_H
