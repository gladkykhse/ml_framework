#ifndef ML_FRAMEWORK_UTILS_H
#define ML_FRAMEWORK_UTILS_H

#include <iostream>
#include <cmath>
#include "Math.h"
#include "Matrix.h"
#include "Vector.h"

template<typename T>
class Utils {
public:
    using vector_type = std::vector<T>;
    using matrix_type = std::vector<std::vector<T>>;

    static T rmse(Vector<T>&, Vector<T>&);

    static T sigmoid(T);

    static Vector<T> softmax(Vector<T>&);
};


#endif //ML_FRAMEWORK_UTILS_H
