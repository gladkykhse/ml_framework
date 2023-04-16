#ifndef ML_FRAMEWORK_LOGISTICREGRESSION_H
#define ML_FRAMEWORK_LOGISTICREGRESSION_H

#include "Matrix.h"
#include "Vector.h"
#include "Math.h"
#include "Utils.h"

template<typename T>
class LogisticRegression {
    explicit LogisticRegression();

    void fit(Matrix<T>, Vector<int>);

    float predict_proba(Vector<T>);
    Vector<T> predict_proba(Matrix<T>);

    int prodict(Vector<T>);
    Vector<int> prodict(Matrix<T>);
};


#endif //ML_FRAMEWORK_LOGISTICREGRESSION_H
