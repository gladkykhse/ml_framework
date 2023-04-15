#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
#include "Math.cpp"
#include <vector>

int main() {
    std::vector<float> my_v1 = {1,1,1,1,1};
    std::vector<float> my_v2 = {1,2,3,4,5};
    Vector<float> v1(my_v1);
    Vector<float> v2(my_v2);

    std::vector<std::vector<float>> my_m1 {
        {1,2,1},
        {2,1,2}
    };
    std::vector<std::vector<float>> my_m2 {
        {1,2},
        {1,2},
        {1,2}
    };
    Matrix<float> m1(my_m1);
    Matrix<float> m2(my_m2);


    Math<float>::outer(v1, v2).print();
    return 0;
}