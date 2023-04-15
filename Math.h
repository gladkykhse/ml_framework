#ifndef ML_FRAMEWORK_MATH_H
#define ML_FRAMEWORK_MATH_H

#include <iostream>
#include <stdexcept>
#include <cmath>

#include "Matrix.h"
#include "Vector.h"

template<typename T>
class Math {
public:
    using vector_type = std::vector<T>;
    using matrix_type = std::vector<std::vector<T>>;

    static Matrix<T> matmul(Matrix<T>&, Matrix<T>&);
    static T inner(Vector<T>&, Vector<T>&);
    static Matrix<T> outer(Vector<T>&, Vector<T>&);
    static Vector<T> exponentiate(Vector<T>&);
    static Matrix<T> exponentiate(Matrix<T>&);
};


#endif //ML_FRAMEWORK_MATH_H
