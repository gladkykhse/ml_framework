#include "Utils.h"

template<typename T>
T Utils<T>::rmse(Vector<T> &y_true, Vector<T> &y_pred) {
    if (y_true.size() != y_pred.size())
        throw std::invalid_argument("Vectors must be of the same length");

    T sum = 0;
    vector_type true_vals = y_true.get();
    vector_type pred_vals = y_pred.get();

    for (int i = 0; i < y_true.size(); i++) {
        sum += pow((true_vals[i] - pred_vals[i]), 2);
    }

    sum /= y_true.size();

    return sqrt(sum);
}

template<typename T>
T Utils<T>::sigmoid(T x) {
    return (1 / (1 + exp(x)));
}

template<typename T>
Vector<T> Utils<T>::sigmoid(Vector<T> &v) {
    vector_type vec = v.get();
    vector_type res_vec;

    for (auto &elem : v.get())
        res_vec.push_back(sigmoid(elem));

    Vector<T> my_vec(res_vec);
    return my_vec;
}

template<typename T>
Matrix<T> Utils<T>::sigmoid(Matrix<T> &M) {
    int height = std::get<0>(M.shape());
    int width = std::get<1>(M.shape());
    matrix_type mat = M.get();
    matrix_type res_mat(height, vector_type(width, 0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res_mat[i][j] = sigmoid(mat[i][j]);
        }
    }
    Matrix<T> my_matrix(res_mat);
    return my_matrix;
}

template<typename T>
Vector<T> Utils<T>::softmax(Vector<T> &v) {
    return (Math<float>::exponentiate(v) / Math<float>::exponentiate(v).sum());
}
