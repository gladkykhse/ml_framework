#include "Vector.h"

template <typename T>
Vector<T>::Vector(vector_type v) : my_vector(v) {}

template <typename T>
void Vector<T>::print() {
    for (auto &item : my_vector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int Vector<T>::size() {
    return my_vector.size();
}

template <typename T>
std::vector<T>& Vector<T>::get() {
    return my_vector;
}

template<typename T>
Vector<T> Vector<T>::vectorOperation(Vector<T> &other, Vector::operations op) {
    if (this->size() != other.size())
        throw std::invalid_argument("Vectors must be of the same size");

    vector_type new_vec(this->size(), 0);
    for (int i = 0; i < this->size(); i++) {
        switch (op) {
            case Add:
                new_vec[i] = my_vector[i] + other.get()[i];
                break;
            case Sub:
                new_vec[i] = my_vector[i] - other.get()[i];
                break;
            case Mul:
                new_vec[i] = my_vector[i] * other.get()[i];
                break;
            case Div:
                T elem = other.get()[i];
                if (elem == 0)
                    throw std::runtime_error("Division by zero");
                new_vec[i] = my_vector[i] / elem;
                break;
        }
    }
    Vector<T> my_vec(new_vec);

    return my_vec;
}

template<typename T>
Vector<T> Vector<T>::scalarOperation(T other, Vector::operations op) {
    vector_type new_vec(this->size(), 0);
    for (int i = 0; i < this->size(); i++) {
        switch (op) {
            case Add:
                new_vec[i] = my_vector[i] + other;
                break;
            case Sub:
                new_vec[i] = my_vector[i] - other;
                break;
            case Mul:
                new_vec[i] = my_vector[i] * other;
                break;
            case Div:
                if (other == 0)
                    throw std::runtime_error("Division by zero");
                new_vec[i] = my_vector[i] / other;
                break;
        }
    }
    Vector<T> my_vec(new_vec);

    return my_vec;
}



template<typename T>
Vector<T> Vector<T>::operator+(Vector<T> &other) {
    return this->vectorOperation(other, Add);
}

template<typename T>
Vector<T> Vector<T>::operator-(Vector<T> &other) {
    return this->vectorOperation(other, Sub);
}

template<typename T>
Vector<T> Vector<T>::operator*(Vector<T> &other) {
    return this->vectorOperation(other, Mul);
}

template<typename T>
Vector<T> Vector<T>::operator/(Vector<T> &other) {
    return this->vectorOperation(other, Div);
}

template<typename T>
Vector<T> Vector<T>::operator+(T other) {
    return scalarOperation(other, Add);
}

template<typename T>
Vector<T> Vector<T>::operator-(T other) {
    return scalarOperation(other, Sub);
}

template<typename T>
Vector<T> Vector<T>::operator*(T other) {
    return scalarOperation(other, Mul);
}

template<typename T>
Vector<T> Vector<T>::operator/(T other) {
    return scalarOperation(other, Div);
}