#ifndef ML_FRAMEWORK_VECTOR_H
#define ML_FRAMEWORK_VECTOR_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix.h"


template <typename T>
class Vector {
public:
    using vector_type = std::vector<T>;
    explicit Vector(vector_type);

    void print();

    int size();

    vector_type& get();

    Vector<T> operator+(Vector<T>&);
    Vector<T> operator-(Vector<T>&);
    Vector<T> operator*(Vector<T>&);
    Vector<T> operator/(Vector<T>&);

    Vector<T> operator+(T);
    Vector<T> operator-(T);
    Vector<T> operator*(T);
    Vector<T> operator/(T);

    Matrix<T> toMatrix();
    T sum();
private:
    enum operations{ Add, Sub, Mul, Div };
    vector_type my_vector;
    Vector<T> vectorOperation(Vector<T>&, operations);
    Vector<T> scalarOperation(T, operations);
};


#endif //ML_FRAMEWORK_VECTOR_H
