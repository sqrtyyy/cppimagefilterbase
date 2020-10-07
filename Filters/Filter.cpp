//
// Created by aleksei on 22.09.2020.
//

#include "Filter.h"

stbi_uc Filter::intensity(pixel &pixel) {
    if(pixel.compPerPixel != 3 ) return 0;
    return (pixel.colors[0] * 3 + pixel.colors[1] * 6 + pixel.colors[2]) / 10;
}
