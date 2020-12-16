//
// Created by aleksei on 27.09.2020.
//

#ifndef STUDENT_TOOLKIT_CONFIGFILTERREADER_H
#define STUDENT_TOOLKIT_CONFIGFILTERREADER_H

#include <map>
#include <fstream>
#include <iostream>

enum class FilterID{
    BLACK_WHITE_ID,
    RED_ID,
    THRESHOLD_ID,
    BLUR,
    EDGE,

};
using std::string;

static const std::map<string , FilterID> nameFilterToID = {
        {"black_white", FilterID::BLACK_WHITE_ID},
        {"Red",         FilterID::RED_ID},
        {"Threshold",   FilterID::THRESHOLD_ID},
        {"Blur",        FilterID::BLUR},
        {"Edge",        FilterID::EDGE}

};

struct FilerParams{
    FilterID name;
    int up;
    int left;
    int bottom;
    int right;

    bool operator==(const FilerParams &rhs) const;

    bool operator!=(const FilerParams &rhs) const;

    friend std::istream& operator>>(std::istream& in, FilerParams& params);
};

class ConfigFilterReader {
private:
    std::ifstream cfgFile;
public:
    explicit ConfigFilterReader(string const& fileName);
    FilerParams* nextFilter();
    ~ConfigFilterReader();
};


#endif //STUDENT_TOOLKIT_CONFIGFILTERREADER_H
