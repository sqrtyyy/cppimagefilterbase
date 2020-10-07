//
// Created by aleksei on 27.09.2020.
//

#include "FilterFabric.h"

Filter *FilterFabric::createFilter(FilerParams params) {
    Filter* filter;
    switch (params.name) {
        case FilterID::BLACK_WHITE_ID:
            filter = new Filter_BW();
            break;
        case FilterID::RED_ID:
            filter = new Filter_Red();
            break;
        case FilterID::THRESHOLD_ID:
            filter = new Filter_Threshold();
            break;
        default:
            filter = nullptr;
    }
    return filter;
}
