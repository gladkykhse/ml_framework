#include "LinearRegression.h"

template<typename T>
LinearRegression<T>::LinearRegression(float learning_rate, float regularization) : learning_rate(learning_rate), regularization(regularization) {}

template<typename T>
void LinearRegression<T>::fit(Matrix<T> &data,
                              Vector<T> &targets,
                              int epochs,
                              int batch_size) {
    Matrix<T> data_with_bias = Utils<T>::addBiasColumn(data);

    int number_of_samples = std::get<0>(data_with_bias.shape());
    int number_of_features = std::get<1>(data_with_bias.shape());

    weights = Utils<T>::uniformVector(number_of_features, 0, 0.1);

    for (int ep = 0 ; ep < epochs; ep++) {
        for (int i = 0; i < (number_of_samples - (number_of_samples % batch_size)); i += batch_size) {
            Vector<T> gradient = Utils<T>::vectorOf(number_of_features, 0);
            for (int j = i; j < i + batch_size; j++) {
                Vector<T> sample = data_with_bias.get_ith(j);
                T target = targets.get_ith(j);

                T predicted = Math<T>::inner(sample, weights);
                predicted = predicted - target;

                Vector<T> grad = (sample * predicted) / batch_size;
                gradient = gradient + grad;
            }
            Vector<T> reg_weights = weights * regularization;
            Vector<T> weights_update = gradient + reg_weights;
            weights_update = weights_update * learning_rate;
            weights = weights - weights_update;
        }
        Vector<T> y_true = targets;
        Matrix<T> matrix_weights = weights.toMatrix().transpose();
        Matrix<T> y_pred = Math<T>::matmul(data_with_bias, matrix_weights);
        y_pred = y_pred.transpose();
        Vector<T> vectorized_preds = y_pred.get_ith(0);

        std::cout << "Epoch: " << (ep + 1) << ", RMSE: " << Utils<T>::rmse(y_true, vectorized_preds) << std::endl;
    }
}

template<typename T>
T LinearRegression<T>::predict(Vector<T> &v) {
    Matrix<T> new_mat = v.toMatrix();
    Matrix<T> to_predict = Utils<T>::addBiasColumn(new_mat);
    if (std::get<1>(to_predict.shape()) != std::get<0>(weights.shape()))
        throw std::invalid_argument("Number of features differs from the train set");
    float res = Math<T>::matmul(to_predict, weights).get_ijth(0, 0);
    return res;
}

template<typename T>
Vector<T> LinearRegression<T>::predict(Matrix<T> &M) {
    Matrix<T> to_predict = Utils<T>::addBiasColumn(M);
    Vector<T> res = Math<T>::matmul(to_predict, weights).transpose().get_ith(0);
    return res;
}

