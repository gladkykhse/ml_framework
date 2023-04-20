#ifndef ML_FRAMEWORK_LINEARREGRESSION_H
#define ML_FRAMEWORK_LINEARREGRESSION_H

#include "Matrix.h"
#include "Vector.h"
#include "Math.h"
#include "Utils.h"

template<typename T>
class LinearRegression {
public:
    LinearRegression(float learning_rate, float regularization);

    void fit(Matrix<T>&, Vector<T>&, int, int);

    T predict(Vector<T>&);
    Vector<T> predict(Matrix<T>&);
private:
    const float learning_rate, regularization;
    Vector<T> weights = Utils<T>::vectorOf(1,0);
};


#endif //ML_FRAMEWORK_LINEARREGRESSION_H
