#ifndef MACHINE_LEARNING_FRAMEWORK_MATRIX_H
#define MACHINE_LEARNING_FRAMEWORK_MATRIX_H

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

    vector_matrix& getMatrix();

    Matrix<T> operator+(Matrix<T>&);
    Matrix<T> operator-(Matrix<T>&);
    Matrix<T> operator*(Matrix<T>&);
    Matrix<T> operator/(Matrix<T>&);

    Matrix<T> operator+(T);
    Matrix<T> operator-(T);
    Matrix<T> operator*(T);
    Matrix<T> operator/(T);
private:
    vector_matrix matrix;
};


#endif //MACHINE_LEARNING_FRAMEWORK_MATRIX_H
