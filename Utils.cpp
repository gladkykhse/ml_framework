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
Vector<T> Utils<T>::softmax(Vector<T> &v) {
    return (Math<float>::exponentiate(v) / Math<float>::exponentiate(v).sum());
}

template<typename T>
Matrix<int> Utils<T>::one_hot(Vector<int> &targets) {
    vector_type target_vals = targets.get();
    int max_elem = *std::max_element(target_vals.begin(), target_vals.end());
    std::vector<std::vector<int>> res_mat(targets.size(), vector_type(max_elem + 1, 0));

    for (int i = 0; i < targets.size(); i++) {
        res_mat[i][target_vals[i]] = 1;
    }

    Matrix<int> my_mat(res_mat);
    return my_mat;
}

template<typename T>
Vector<int> Utils<T>::from_one_hot(Matrix<int> &M) {
    matrix_type one_hot = M.get();
    vector_type res_vec;
    for (int i = 0; i < one_hot.size(); i++) {
        for (int j = 0; j < one_hot[0].size(); j++) {
            if (one_hot[i][j] == 1) {
                res_vec.push_back(j);
                break;
            }
        }
    }
    Vector<int> my_vec(res_vec);

    return my_vec;
}

template<typename T>
float Utils<T>::accuracy(Vector<int> &y_true, Vector<int> &y_pred) {
    if (y_true.size() != y_pred.size())
        throw std::invalid_argument("Vectors must be of the same length");

    vector_type true_vals = y_true.get();
    vector_type pred_vals = y_pred.get();

    float counter = 0;
    for (int i = 0; i < true_vals.size(); i++) {
        if (true_vals[i] == pred_vals[i])
            counter++;
    }

    return (counter / y_true.size());
}

template<typename T>
float Utils<T>::accuracy(Vector<int> &y_true , Matrix<int> &y_pred) {
    Vector<int> flattened_preds = from_one_hot(y_pred);
    return accuracy(y_true, flattened_preds);
}
