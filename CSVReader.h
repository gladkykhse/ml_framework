#ifndef ML_FRAMEWORK_CSVREADER_H
#define ML_FRAMEWORK_CSVREADER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Matrix.h"

template<typename T>
class CSVReader {
public:
    static Matrix<T> readFile(std::string, bool);
private:
    static std::vector<T> parseLine(std::string);
    static T strToT(std::string);
};


#endif //ML_FRAMEWORK_CSVREADER_H
