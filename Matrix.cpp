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
std::vector<std::vector<T>>& Matrix<T>::getMatrix() {
    return matrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& other) {
    if (matrix.size() != std::get<0>(other.shape()) || matrix[0].size() != std::get<1>(other.shape()))
        throw std::invalid_argument("Matrices must be of the same size");

    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] + other.getMatrix()[i][j];
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& other) {
    if (matrix.size() != std::get<0>(other.shape()) || matrix[0].size() != std::get<1>(other.shape()))
        throw std::invalid_argument("Matrices must be of the same size");

    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] - other.getMatrix()[i][j];
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& other) {
    if (matrix.size() != std::get<0>(other.shape()) || matrix[0].size() != std::get<1>(other.shape()))
        throw std::invalid_argument("Matrices must be of the same size");

    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] * other.getMatrix()[i][j];
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(Matrix<T>& other) {
    if (matrix.size() != std::get<0>(other.shape()) || matrix[0].size() != std::get<1>(other.shape()))
        throw std::invalid_argument("Matrices must be of the same size");

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (other.getMatrix()[i][j] == 0)
                throw std::runtime_error("Division by zero");
        }
    }

    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] / other.getMatrix()[i][j];
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(T other) {
    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] + other;
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(T other) {
    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] - other;
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(T other) {
    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] * other;
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(T other) {
    if (other == 0)
        throw std::runtime_error("Division by zero");

    vector_matrix newMatrix(matrix.size(), std::vector<T>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            newMatrix[i][j] = matrix[i][j] / other;
        }
    }

    Matrix<T>myMatrix (newMatrix);

    return myMatrix;
}