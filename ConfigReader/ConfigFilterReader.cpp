//
// Created by aleksei on 27.09.2020.
//

#include "ConfigFilterReader.h"

FilerParams ConfigFilterReader::parseFile(const string &fileName) {
    std::ifstream cfgFile;
    cfgFile.open(fileName);
    if(cfgFile.is_open()){
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

