#include "LinearRegression.h"

template<typename T>
LinearRegression<T>::LinearRegression(float learning_rate, float regularization) : learning_rate(learning_rate), regularization(regularization) {}

template<typename T>
void LinearRegression<T>::fit(Matrix<T> &data,
                              Vector<T> &targets,
                              T epochs,
                              T batch_size) {

    Matrix<T> data_with_bias = Utils<T>::addBiasColumn(data);

    int number_of_samples = std::get<0>(data_with_bias.shape());
    int number_of_features = std::get<1>(data_with_bias.shape());

    weights = Utils<T>::uniformMatrix(number_of_features, 1, 0, 0.1);
//    weights.print();

    for (int epoch = 1; epoch < epochs + 1; epoch++) {
        for (int i = 0; i < number_of_samples; i += batch_size) {
            Matrix<T> gradient = Utils<T>::matrixOf(1, number_of_features, 0);
            if (i + batch_size < number_of_samples) {
                for (int j = i; j < (i + batch_size); j++) {
                    Vector<T> sample = data_with_bias.get_ith(j);
                    T target = targets.get_ith(j);

                    Matrix<T> matrix_sample = sample.toMatrix();

                    T my_prediction = Math<T>::matmul(matrix_sample, weights).get_ijth(0, 0);
                    std::cout << (my_prediction - target) << std::endl;
                    gradient = ((matrix_sample * (my_prediction - target)) / batch_size) + gradient;
                }
                Matrix<T> transposed_gradient = gradient.transpose();
                Matrix<T> regularized_weights = (weights * regularization);
                Matrix<T> weights_update = ((transposed_gradient + regularized_weights) * learning_rate);
                weights = weights - weights_update;
            }
        }
        Vector<T> y_true = targets;
        Vector<T> y_pred = predict(data);
        std::cout << "Epoch: " << epoch << ", RMSE: " << Utils<T>::rmse(y_true, y_pred) << std::endl;
        std::cout << "Weights learned: ";
        weights.transpose().print();
//        std::cout << std::endl;
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

