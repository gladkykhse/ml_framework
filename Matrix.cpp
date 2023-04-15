#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(vector_matrix matrix) : matrix(matrix) {};

template <typename T>
void Matrix<T>::print() {
    for (auto &i : matrix) {
        for (auto &j : i) {
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}

template<typename T>
std::tuple<int, int> Matrix<T>::shape() {
    std::tuple<int, int> shape = std::tuple<int, int>(matrix.size(), matrix[0].size());
    return shape;
}

template<typename T>
std::vector<std::vector<T>>& Matrix<T>::get() {
    return matrix;
}

template<typename T>
Matrix<T> Matrix<T>::matrixOperation(Matrix<T> &other, Matrix::operations op) {
    if (matrix.size() != std::get<0>(other.shape()) || matrix[0].size() != std::get<1>(other.shape()))
        throw std::invalid_argument("Matrices must be of the same size");

    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            switch (op) {
                case Add:
                    newMatrix[i][j] = matrix[i][j] + other.get()[i][j];
                    break;
                case Sub:
                    newMatrix[i][j] = matrix[i][j] - other.get()[i][j];
                    break;
                case Mul:
                    newMatrix[i][j] = matrix[i][j] * other.get()[i][j];
                    break;
                case Div:
                    T elem = other.get()[i][j];
                    if (elem == 0)
                        throw std::runtime_error("Division by zero");
                    newMatrix[i][j] = matrix[i][j] / elem;
                    break;
            }
        }
    }
    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::scalarOperation(T other, Matrix::operations op) {
    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            switch (op) {
                case Add:
                    newMatrix[i][j] = matrix[i][j] + other;
                    break;
                case Sub:
                    newMatrix[i][j] = matrix[i][j] - other;
                    break;
                case Mul:
                    newMatrix[i][j] = matrix[i][j] * other;
                    break;
                case Div:
                    if (other == 0)
                        throw std::runtime_error("Division by zero");
                    newMatrix[i][j] = matrix[i][j] / other;
                    break;
            }
        }
    }
    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &other) {
    return matrixOperation(other, Add);
}

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &other) {
    return matrixOperation(other, Sub);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &other) {
    return matrixOperation(other, Mul);
}

template<typename T>
Matrix<T> Matrix<T>::operator/(Matrix<T> &other) {
    return matrixOperation(other, Div);
}

template<typename T>
Matrix<T> Matrix<T>::operator+(T other) {
    return scalarOperation(other, Add);
}

template<typename T>
Matrix<T> Matrix<T>::operator-(T other) {
    return scalarOperation(other, Sub);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T other) {
    return scalarOperation(other, Mul);
}

template<typename T>
Matrix<T> Matrix<T>::operator/(T other) {
    return scalarOperation(other, Div);
}


