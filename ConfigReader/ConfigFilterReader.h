//
// Created by aleksei on 27.09.2020.
//

#ifndef STUDENT_TOOLKIT_CONFIGFILTERREADER_H
#define STUDENT_TOOLKIT_CONFIGFILTERREADER_H

#include <map>
#include <fstream>

enum class FilterID{
    BLACK_WHITE_ID,
    RED_ID,
    THRESHOLD_ID,

};
using std::string;

static const std::map<string , FilterID> nameFilterToID = {
        {"black_white", FilterID::BLACK_WHITE_ID},
        {"Red",         FilterID::RED_ID},
        {"Threshold",   FilterID::THRESHOLD_ID}
};

struct FilerParams{
    FilterID name;
    int up;
    int left;
    int bottom;
    int right;
};

class ConfigFilterReader {
public:
    static FilerParams parseFile(string const& fileName);
};


#endif //STUDENT_TOOLKIT_CONFIGFILTERREADER_H
