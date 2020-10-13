//
// Created by aleksei on 28.09.2020.
//

#include "ImageZone.h"

ImageZone::ImageZone(int up, int left, int bottom, int right, image_data &img) : imgData(img){
    this->up = up == 0 ? 0 : img.h / up;
    this->bottom = bottom == 0 ? 0 : img.h / bottom;
    this->left = left == 0 ? 0 : img.w / left;
    this->right = right == 0 ? 0 : img.w / right;
    curPixel.compPerPixel = img.compPerPixel;
}

pixel& ImageZone::get_pixel(unsigned int row,unsigned int column) {
    unsigned int idx = (imgData.w * (up + row) + (column + left)) * imgData.compPerPixel;
    for(int i = 0; i < curPixel.compPerPixel; i++){
        curPixel.colors[i] = imgData.pixels[idx + i];
    }
    return curPixel;
}

unsigned int ImageZone::get_width() const {
    return right - left;
}

unsigned int ImageZone::get_height() const {
    return bottom - up;
}

bool ImageZone::set_pixel(unsigned int row,unsigned int column, pixel newPixel) {
    if(column > (right - left) || row > (bottom - up) || newPixel.compPerPixel != imgData.compPerPixel) return false;
    unsigned int idx = (imgData.w * (up + row) + (column + left)) * (unsigned int)imgData.compPerPixel;
    for(int i = 0; i < 3; i++){
        imgData.pixels[idx + i] = newPixel.colors[i];
    }
    return true;
}

ImageZone::ImageZone(FilerParams &params, image_data &img) {
    up = params.up;
    bottom = params.bottom;
    left = params.left;
    right = params.right;
    imgData = img;
}

ImageZone::ImageZone(FilerParams params, image_data data) {
    this->up = params.up == 0 ? 0 : data.h / params.up;
    this->bottom = params.bottom == 0 ? 0: data.h / params.bottom;
    this->left = params.left == 0 ? 0 : data.w / params.left;
    this->right = params.right == 0 ? 0 : data.w / params.right;
    curPixel.compPerPixel = data.compPerPixel;
    imgData = data;
}
