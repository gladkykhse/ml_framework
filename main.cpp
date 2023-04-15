#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
#include "Math.cpp"
#include "Utils.cpp"

#include <vector>

int main() {
    std::vector<int> my_v1 = {1,1,1,1,1};
    std::vector<int> my_v2 = {1,2,2,2,1};
    Vector<int> v1(my_v1);
    Vector<int> v2(my_v2);

    std::vector<std::vector<float>> my_m1 {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::vector<std::vector<float>> my_m2 {
        {1,2},
        {1,2},
        {1,2}
    };
    Matrix<float> m1(my_m1);
    Matrix<float> m2(my_m2);

    Matrix<int> a = Utils<int>::one_hot(v1);

    std::cout << Utils<int>::accuracy(v2, a) << std::endl;

    return 0;
}