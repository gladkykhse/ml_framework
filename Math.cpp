#include "Math.h"

template<typename T>
Matrix<T> Math<T>::matmul(Matrix<T> A, Matrix<T> B) {
    if (std::get<1>(A.shape()) != std::get<0>(B.shape()))
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");

    int height = std::get<0>(A.shape()), width = std::get<1>(B.shape());
    matrix_type res_matrix(height, vector_type(width, 0));

    matrix_type matA = A.get();
    matrix_type matB = B.get();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            T sum = 0;
            for (int k = 0; k < std::get<0>(B.shape()); k++) {
                sum += matA[i][k] * matB[k][j];
            }
            res_matrix[i][j] = sum;
        }
    }
    Matrix<T> my_matrix(res_matrix);

    return my_matrix;
}

template<typename T>
T Math<T>::inner(Vector<T> v1, Vector<T> v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("Vectors must be of the same size");

    vector_type vec1 = v1.get();
    vector_type vec2 = v2.get();

    T res = 0;
    for (int i = 0; i < v1.size(); i++) {
        res += vec1[i] * vec2[i];
    }

    return res;
}

template<typename T>
Matrix<T> Math<T>::outer(Vector<T> v1, Vector<T> v2) {
    vector_type vec1 = v1.get();
    vector_type vec2 = v2.get();
    matrix_type res_matrix(v1.size(), std::vector<T>(v2.size(), 0));

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            res_matrix[i][j] = vec1[i] * vec2[j];
        }
    }

    Matrix<T> my_matrix(res_matrix);
    return my_matrix;
}
