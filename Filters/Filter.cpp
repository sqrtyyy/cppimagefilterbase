//
// Created by aleksei on 22.09.2020.
//

#include "Filter.h"

stbi_uc Filter::intensity(pixel &pixel) {
    if(pixel.compPerPixel < 3 ) return 0;
    return (3 * pixel.colors[0] + 6 * pixel.colors[1] + pixel.colors[2]) / 10;
}
