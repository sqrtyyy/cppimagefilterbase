//
// Created by aleksei on 27.09.2020.
//

#include "ConfigFilterReader.h"

FilerParams ConfigFilterReader::nextFilter() {
    if(cfgFile.is_open() && !cfgFile.eof()){
        FilerParams  filterParams{};
        string filterName;
        cfgFile >> filterName;
        auto  filterNameID = nameFilterToID.find(filterName);
        if (filterNameID != nameFilterToID.end()) {
            filterParams.name = filterNameID->second;
        }
        cfgFile >> filterParams.up >> filterParams.left >> filterParams.bottom >> filterParams.right;
        return filterParams;
    } else {
        return {};
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
