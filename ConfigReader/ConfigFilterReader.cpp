//
// Created by aleksei on 27.09.2020.
//

#include "ConfigFilterReader.h"

FilerParams* ConfigFilterReader::nextFilter() {
    if(cfgFile.is_open() && !cfgFile.eof()){
        auto*  filterParams = new FilerParams();
        string filterName;
        cfgFile >> filterName;
        auto  filterNameID = nameFilterToID.find(filterName);
        if (filterNameID != nameFilterToID.end()) {
            filterParams->name = filterNameID->second;
        }
        cfgFile >> filterParams->up >> filterParams->left >> filterParams->bottom >> filterParams->right;
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
