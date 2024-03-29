#include "Utils.h"

template<typename T>
T Utils<T>::rmse(Vector<T> &y_true, Vector<T> &y_pred) {
    if (y_true.size() != y_pred.size())
        throw std::invalid_argument("Vectors must be of the same length");

    T sum = 0;

    for (int i = 0; i < y_true.size(); i++) {
        sum += pow((y_true.get_ith(i) - y_pred.get_ith(i)), 2);
    }

    sum /= y_true.size();

    return sqrt(sum);
}

template<typename T>
T Utils<T>::sigmoid(T x) {
    return (1 / (1 + exp(x)));
}

template<typename T>
Matrix<T> Utils<T>::one_hot(Vector<int> &targets) {
    std::vector<int> target_vals = targets.get();
    int max_elem = *std::max_element(target_vals.begin(), target_vals.end());
    matrix_type res_mat(targets.size(), vector_type(max_elem + 1, 0));

    for (int i = 0; i < targets.size(); i++) {
        res_mat[i][target_vals[i]] = 1;
    }

    Matrix<T> my_mat(res_mat);
    return my_mat;
}

template<typename T>
Vector<int> Utils<T>::from_one_hot(Matrix<T> &M) {
    matrix_type one_hot = M.get();
    std::vector<int> res_vec;
    for (int i = 0; i < std::get<0>(M.shape()); i++) {
        for (int j = 0; j < std::get<1>(M.shape()); j++) {
            if (M.get_ijth(i, j) == 1) {
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

    float counter = 0;
    for (int i = 0; i < y_true.size(); i++) {
        if (y_true.get_ith(i) == y_pred.get_ith(i))
            counter++;
    }

    return (counter / y_true.size());
}

template<typename T>
float Utils<T>::accuracy(Vector<int> &y_true , Matrix<int> &y_pred) {
    Vector<int> flattened_preds = from_one_hot(y_pred);
    return accuracy(y_true, flattened_preds);
}

template<typename T>
Matrix<T> Utils<T>::uniformMatrix(int height, int width, T mean, T std) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<T> d{mean, std};
    matrix_type rand_matrix(height, vector_type(width, 0));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            rand_matrix[i][j] = d(gen);
        }
    }

    Matrix<T> res_mat(rand_matrix);
    return res_mat;
}

template<typename T>
Vector<T> Utils<T>::uniformVector(int length, T mean, T std) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<T> d{mean, std};
    vector_type v(length, 0);

    for (int i = 0; i < length; i++) {
        v[i] = d(gen);
    }

    Vector<T> res_vec(v);
    return res_vec;
}

template<typename T>
Matrix<T> Utils<T>::addBiasColumn(Matrix<T> &M) {
    matrix_type mat = M.get();
    for (auto &row : mat) {
        row.push_back(1);
    }
    Matrix<T> res(mat);
    return res;
}

template<typename T>
Matrix<T> Utils<T>::matrixOf(int height, int width, T val) {
    matrix_type my_mat(height, vector_type(width, val));
    Matrix<T> res_mat(my_mat);
    return res_mat;
}

template<typename T>
Vector<T> Utils<T>::vectorOf(int length, T val) {
    vector_type my_vec(length, val);
    Vector<T> res_vec(my_vec);
    return res_vec;
}

template<typename T>
float Utils<T>::crossEntropy(Vector<T> &y_true, Vector<T> &y_pred) {
    float loss = 0.0;
    for (int i = 0; i < y_pred.size(); i++) {
//        if (y_pred.get_ith(i) <= 0)
//            continue;
        loss += y_true.get_ith(i) * std::log(y_pred.get_ith(i));
    }
    return -loss;
}

template<typename T>
float Utils<T>::crossEntropy(Matrix<T> &y_true, Matrix<T> &y_pred) {
    float loss = 0.0;
    const int batch_size = std::get<0>(y_true.shape());
    const int num_classes = std::get<1>(y_true.shape());

    for (int i = 0; i < batch_size; i++) {
        for (int j = 0; j < num_classes; j++) {
            loss += y_true.get_ijth(i, j) * std::log(y_pred.get_ijth(i, j));
        }
    }
    return -loss / batch_size;
}

template<typename T>
Vector<T> Utils<T>::softmax(Vector<T> &v) {
    T max = *max_element(v.get().begin(), v.get().end());
    Vector<T> scaled_v = v - max;
    return (Math<T>::exponentiate((scaled_v)) / Math<T>::exponentiate(scaled_v).sum());
}

template<typename T>
Matrix<T> Utils<T>::softmax(Matrix<T> &M) {
    matrix_type res(std::get<0>(M.shape()), vector_type(std::get<1>(M.shape()), 0));
    for (int i = 0; i < std::get<0>(M.shape()); i++) {
        Vector<T> currentRow = M.get_ith(i);
        T max = *max_element(currentRow.get().begin(), currentRow.get().end());
        currentRow = currentRow - max;

        currentRow = (Math<T>::exponentiate(currentRow) / Math<T>::exponentiate(currentRow).sum());
        for (int j = 0; j < currentRow.size(); j++) {
            res[i][j] = currentRow.get_ith(j);
        }
    }
    Matrix<T> res_mat(res);
    return res_mat;
}

template<typename T>
bool Utils<T>::isNan(Matrix<T> &M) {
    for (int i = 0; i < std::get<0>(M.shape()); i++) {
        for (int j = 0; j < std::get<1>(M.shape()); j++) {
            if (M.get_ijth(i, j) != M.get_ijth(i, j)) {
                return true;
            }
        }
    }
    return false;
}

template<typename T>
bool Utils<T>::isNan(Vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v.get_ith(i) != v.get_ith(i))
            return true;
    }
    return false;
}
