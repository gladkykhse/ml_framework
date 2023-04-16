#include "LogisticRegression.h"

template<typename T>
LogisticRegression<T>::LogisticRegression(float learning_rate, float regularization) : learning_rate(learning_rate), regularization(regularization) {}

template<typename T>
void LogisticRegression<T>::fit(Matrix<T> &data,
                                Vector<int> &targets,
                                int epochs,
                                int batch_size) {
    Matrix<T> data_with_bias = Utils<T>::addBiasColumn(data);
    Matrix<T> one_hot_targets = Utils<T>::one_hot(targets);

    int number_of_samples = std::get<0>(data_with_bias.shape());
    int number_of_features = std::get<1>(data_with_bias.shape());
    int number_of_classes = std::get<1>(one_hot_targets.shape());

    weights = Utils<T>::uniformMatrix(number_of_features, number_of_classes, 0, 1);

    for (int epoch = 1; epoch < epochs + 1; epoch++) {
        for (int i = 0; i < number_of_samples; i += batch_size) {
            Matrix<T> gradient = Utils<T>::matrixOf(number_of_features, number_of_classes, 0);
            for (int j = i; j < (i + batch_size); j++) {
                Vector<T> sample = data_with_bias.get_ith(j);

                Matrix<T> matrixSample = sample.toMatrix();
                Matrix<T> pred = Math<T>::matmul(matrixSample, weights);

                Vector<T> pred_i = pred.get_ith(0);
                Vector<T> soft_dif = Utils<T>::softmax(pred_i);
                Vector<T> target_i = one_hot_targets.get_ith(j);

                soft_dif = (soft_dif - target_i);
                Matrix<T> lhs = soft_dif.toMatrix().transpose();

                Matrix<T> grad = Math<T>::matmul(lhs, matrixSample);
                grad = grad.transpose();
                grad = (grad / batch_size);
                gradient = gradient + grad;
            }
            Matrix<T> weights_update = (gradient * learning_rate);
            weights = weights - weights_update;
        }
        Matrix<T> probs = predict_proba(data);
        Vector<int> y_pred = predict(data);
        Vector<int> y_true = targets;
        std::cout << "Epoch: " << epoch << ", Loss: " << Utils<T>::crossEntropy(one_hot_targets, probs) << ", Accuracy: " << Utils<T>::accuracy(y_true, y_pred) << std::endl;
    }
}

template<typename T>
Matrix<T> LogisticRegression<T>::predict_proba(Matrix<T> &data) {
    Matrix<T> data_with_bias = Utils<T>::addBiasColumn(data);
    Matrix<T> multiplied = Math<T>::matmul(data_with_bias, weights);
    return Utils<T>::softmax(multiplied);
}

template<typename T>
Vector<int> LogisticRegression<T>::predict(Matrix<T> &data) {
    std::vector<int> classes;
    Matrix<T> data_vals = data;
    Matrix<T> probs = predict_proba(data_vals);

    for (int i = 0; i < std::get<0>(probs.shape()); i++) {
        std::vector<T> v = probs.get_ith(i).get();
        auto it = std::minmax_element(v.begin(), v.end());
        int max_idx = std::distance(v.begin(), it.second);
        classes.push_back(max_idx);
    }

    Vector<int> res_vec(classes);
    return res_vec;
}
