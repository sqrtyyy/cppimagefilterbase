//
// Created by aleksei on 06.10.2020.
//

#ifndef STUDENT_TOOLKIT_KERNFILTER_H
#define STUDENT_TOOLKIT_KERNFILTER_H

#include "Filter.h"
#include <vector>
using std::vector;

class KernFilter : public Filter {
protected:
    vector<int> kern = {};
    unsigned int kernSize = 0;
    ~KernFilter() override;
};


#endif //STUDENT_TOOLKIT_KERNFILTER_H
