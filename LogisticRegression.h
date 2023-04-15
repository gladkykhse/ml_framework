#ifndef ML_FRAMEWORK_LOGISTICREGRESSION_H
#define ML_FRAMEWORK_LOGISTICREGRESSION_H

#include "Matrix.h"
#include "Vector.h"
#include "Math.h"
#include "Utils.h"

class LogisticRegression {
    explicit LogisticRegression();

    void fit(Matrix<float>, Vector<int>);

    float predict_proba(Vector<float>);
    Vector<float> predict_proba(Matrix<float>);

    int prodict(Vector<float>);
    Vector<int> prodict(Matrix<float>);
};


#endif //ML_FRAMEWORK_LOGISTICREGRESSION_H
