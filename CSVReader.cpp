#include "CSVReader.h"

template<typename T>
T CSVReader<T>::strToT(std::string n) {
    try {
        if (std::is_same_v<T, int>)
            return std::stoi(n);
        else if (std::is_same_v<T, float>)
            return std::stof(n);
        else if (std::is_same_v<T, double>)
            return std::stod(n);
        else
            throw std::runtime_error("Type is not supported");
    } catch (...) {
        throw std::runtime_error("Conversion to the numeric type failed");
    }
}

template<typename T>
std::vector<T> CSVReader<T>::parseLine(std::string line, bool includeLeft) {
    std::vector<T> my_line;
    std::string buffer = "";
    const char delim = ',';

    for (auto &chr : line) {
        if (chr == delim) {
            if (buffer != "") {
                my_line.push_back(strToT(buffer));
                buffer = "";
            }
        }
        else {
            buffer += chr;
        }
    }
    if (!includeLeft)
        my_line.erase(my_line.begin());
    return my_line;
}

template<typename T>
Matrix<T> CSVReader<T>::readFile(std::string filename, bool includeTop, bool includeLeft) {
    std::vector<std::vector<T>> data;

    std::string file_str;
    std::ifstream file(filename);

    bool first = true;

    if (!file.good()) {
        std::cout << "Cannot open file \"" << filename << "\"" << std::endl;
        std::cout << "Cannot open file \"" << filename << "\"" << std::endl;
        exit(8);
    }

    while ( file ) {
        std::getline(file, file_str);
        if (first and !includeTop) {
            first = false;
            continue;
        }

        if (file.fail()) {
            if (file.eof())
                break;
            std::cout << "Cannot read from the file" << std::endl;
            exit(8);
        }
        data.push_back(parseLine(file_str, includeLeft));
    }


    Matrix<T> res_mat(data);
    return res_mat;
}