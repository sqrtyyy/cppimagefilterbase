//
// Created by aleksei on 27.09.2020.
//

#ifndef STUDENT_TOOLKIT_FILTERFABRIC_H
#define STUDENT_TOOLKIT_FILTERFABRIC_H

#include "Filter_Red.h"
#include "Filter_BW.h"
#include "../ConfigReader/ConfigFilterReader.h"

class FilterFabric {
public:
    static Filter* createFilter (FilerParams params);
};


#endif //STUDENT_TOOLKIT_FILTERFABRIC_H
