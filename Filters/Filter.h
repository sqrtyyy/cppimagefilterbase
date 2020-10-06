//
// Created by aleksei on 22.09.2020.
//

#ifndef STUDENT_TOOLKIT_FILTER_H
#define STUDENT_TOOLKIT_FILTER_H

#include "../ImageZone/ImageZone.h"


class Filter {

public:
    virtual void filter_image(ImageZone& img_data) = 0;
    virtual ~Filter()= default;
};


#endif //STUDENT_TOOLKIT_FILTER_H
