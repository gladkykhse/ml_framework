#include "Math.h"

template<typename T>
Matrix<T> Math<T>::matmul(Matrix<T> &A, Matrix<T> &B) {
    if (std::get<1>(A.shape()) != std::get<0>(B.shape()))
        throw std::invalid_argument("Matrix dimensions are not compatible for multiplication");

    int height = std::get<0>(A.shape()), width = std::get<1>(B.shape());
    matrix_type res_matrix(height, vector_type(width, 0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            T sum = 0;
            for (int k = 0; k < std::get<0>(B.shape()); k++) {
                sum += A.get_ijth(i, k) * B.get_ijth(k, j);
            }
            res_matrix[i][j] = sum;
        }
    }
    Matrix<T> my_matrix(res_matrix);

    return my_matrix;
}

template<typename T>
T Math<T>::inner(Vector<T> &v1, Vector<T> &v2) {
    if (v1.size() != v2.size())
        throw std::invalid_argument("Vectors must be of the same size");

    T res = 0;
    for (int i = 0; i < v1.size(); i++) {
        res += v1.get_ith(i) * v2.get_ith(i);
    }

    return res;
}

template<typename T>
Matrix<T> Math<T>::outer(Vector<T> &v1, Vector<T> &v2) {
    matrix_type res_matrix(v1.size(), std::vector<T>(v2.size(), 0));

    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            res_matrix[i][j] = v1.get_ith(i) * v2.get_ith(j);
        }
    }

    Matrix<T> my_matrix(res_matrix);
    return my_matrix;
}

template<typename T>
Vector<T> Math<T>::exponentiate(Vector<T> &v) {
    vector_type res_vec;
    for (int i = 0; i < v.size(); i++) {
        res_vec.push_back(exp(v.get_ith(i)));
    }
    Vector<T> my_vec(res_vec);
    return my_vec;
}

template<typename T>
Matrix<T> Math<T>::exponentiate(Matrix<T> &M) {
    int height = std::get<0>(M.shape());
    int width = std::get<1>(M.shape());
    matrix_type res_mat(height, vector_type(width, 0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res_mat[i][j] = exp(M.get_ijth(i, j));
        }
    }
    Matrix<T> my_matrix(res_mat);
    return my_matrix;
}


