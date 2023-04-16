#ifndef MACHINE_LEARNING_FRAMEWORK_MATRIX_H
#define MACHINE_LEARNING_FRAMEWORK_MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <tuple>
template<typename T>
class Matrix;
#include "Vector.h"

template <typename T>
class Matrix {
public:
    using matrix_type = std::vector<std::vector<T>>;
    explicit Matrix(matrix_type);

    void print();

    std::tuple<int, int> shape();

    matrix_type& get();
    Vector<T> get_ith(int);
    T get_ijth(int, int);

    void print_shape();

    Matrix<T> operator+(Matrix<T>&);
    Matrix<T> operator-(Matrix<T>&);
    Matrix<T> operator*(Matrix<T>&);
    Matrix<T> operator/(Matrix<T>&);

    Matrix<T> operator+(T);
    Matrix<T> operator-(T);
    Matrix<T> operator*(T);
    Matrix<T> operator/(T);

    Matrix<T> transpose();
    Vector<T> sum();


private:
    enum operations{ Add, Sub, Mul, Div };
    matrix_type matrix;
    Matrix<T> matrixOperation(Matrix<T>&, Matrix::operations);
    Matrix<T> scalarOperation(T, Matrix::operations);
};


#endif //MACHINE_LEARNING_FRAMEWORK_MATRIX_H
