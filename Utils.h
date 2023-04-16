#ifndef ML_FRAMEWORK_UTILS_H
#define ML_FRAMEWORK_UTILS_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>

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
    static Matrix<T> softmax(Matrix<T>&);
    static Matrix<T> one_hot(Vector<int>&);
    static Vector<int> from_one_hot(Matrix<int>&);
    static float accuracy(Vector<int>&, Vector<int>&);
    static float accuracy(Vector<int>&, Matrix<int>&);
    static Matrix<T> uniformMatrix(int, int, T, T);
    static Vector<T> uniformVector(int, T, T);
    static Matrix<T> addBiasColumn(Matrix<T>&);
    static Matrix<T> matrixOf(int, int, T);
    static Vector<T> vectorOf(int, T);
    static float crossEntropy(Vector<T>&, Vector<T>&);
    static float crossEntropy(Matrix<T>&, Matrix<T>&);
};


#endif //ML_FRAMEWORK_UTILS_H
