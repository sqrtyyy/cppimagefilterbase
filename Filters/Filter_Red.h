//
// Created by aleksei on 22.09.2020.
//

#ifndef STUDENT_TOOLKIT_FILTER_RED_H
#define STUDENT_TOOLKIT_FILTER_RED_H

#include "Filter.h"

class Filter_Red: public Filter {
public:
    void filter_image(ImageZone& img_data) override;
};


#endif //STUDENT_TOOLKIT_FILTER_RED_H
