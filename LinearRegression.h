#ifndef ML_FRAMEWORK_LINEARREGRESSION_H
#define ML_FRAMEWORK_LINEARREGRESSION_H

#include "Matrix.h"
#include "Vector.h"
#include "Math.h"
#include "Utils.h"


class LinearRegression {
    explicit LinearRegression();

    void fit(Matrix<float>, Vector<int>);

    float predict(Vector<float>);
    float predict(Matrix<float>);
};


#endif //ML_FRAMEWORK_LINEARREGRESSION_H
