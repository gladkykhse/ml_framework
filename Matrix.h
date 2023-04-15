#ifndef MACHINE_LEARNING_FRAMEWORK_MATRIX_H
#define MACHINE_LEARNING_FRAMEWORK_MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <tuple>

template <typename T>
class Matrix {
public:
    using vector_matrix  = std::vector<std::vector<T>>;
    explicit Matrix(vector_matrix);

    void print();

    std::tuple<int, int> shape();

    vector_matrix& get();

    Matrix<T> operator+(Matrix<T>&);
    Matrix<T> operator-(Matrix<T>&);
    Matrix<T> operator*(Matrix<T>&);
    Matrix<T> operator/(Matrix<T>&);

    Matrix<T> operator+(T);
    Matrix<T> operator-(T);
    Matrix<T> operator*(T);
    Matrix<T> operator/(T);

private:
    enum operations{ Add, Sub, Mul, Div };
    vector_matrix matrix;
    Matrix<T> matrixOperation(Matrix<T>&, Matrix::operations);
    Matrix<T> scalarOperation(T, Matrix::operations);
};


#endif //MACHINE_LEARNING_FRAMEWORK_MATRIX_H
