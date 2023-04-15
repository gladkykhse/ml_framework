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