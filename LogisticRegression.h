#ifndef ML_FRAMEWORK_LOGISTICREGRESSION_H
#define ML_FRAMEWORK_LOGISTICREGRESSION_H

#include "Matrix.h"
#include "Vector.h"
#include "Math.h"
#include "Utils.h"
#include <algorithm>

template<typename T>
class LogisticRegression {
public:
    LogisticRegression(float, float);

    void fit(Matrix<T>&, Vector<int>&, int, int);

    Matrix<T> predict_proba(Matrix<T>&);
    Vector<int> predict(Matrix<T>&);
private:
    const float learning_rate, regularization;
    Matrix<T> weights = Utils<T>::matrixOf(1,1,1);
};


#endif //ML_FRAMEWORK_LOGISTICREGRESSION_H
