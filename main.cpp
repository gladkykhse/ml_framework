#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
#include <vector>

int main() {
    std::vector<std::vector<float>> my_m1 {
        {1,2,3},
        {2,2,4},
        {5,2,5},
    };
    std::vector<std::vector<float>> my_m2 {
        {2,2,4},
        {1,2,3},
        {5,2,5},
    };
    Matrix<float> m1(my_m1);
    Matrix<float> m2(my_m2);

    std::vector<float> my_v1 = {1,2,3,4,5};
    std::vector<float> my_v2 = {1,2,3,4,5};
    Vector<float> v1(my_v1);
    Vector<float> v2(my_v2);

    (m1 + 1).print();
    (m1 - 1).print();
    (m1 * 2).print();
    (m1 / 2).print();

    return 0;
}