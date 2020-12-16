//
// Created by aleksei on 27.09.2020.
//

#include "ConfigFilterReader.h"

FilerParams* ConfigFilterReader::nextFilter() {
    if(cfgFile.is_open() && !cfgFile.eof()){
        auto*  filterParams = new FilerParams();
        cfgFile >> *filterParams;
        return filterParams;
    } else {
        return nullptr;
    }
}

ConfigFilterReader::ConfigFilterReader(const string &fileName) {
    cfgFile.open(fileName);
}

ConfigFilterReader::~ConfigFilterReader() {
    cfgFile.close();

}

bool FilerParams::operator==(const FilerParams &rhs) const {
    return name == rhs.name &&
           up == rhs.up &&
           left == rhs.left &&
           bottom == rhs.bottom &&
           right == rhs.right;
}

bool FilerParams::operator!=(const FilerParams &rhs) const {
    return !(rhs == *this);
}


std::istream &operator>>(std::istream &in, FilerParams& params) {
    string filterName;
    in >> filterName;
    auto  filterNameID = nameFilterToID.find(filterName);
    if (filterNameID != nameFilterToID.end()) {
        params.name = filterNameID->second;
    }
    in >> params.up >> params.left >> params.bottom >> params.right;
    return in;
}
