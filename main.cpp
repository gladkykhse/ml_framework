#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
#include "Math.cpp"
#include "Utils.cpp"
#include "LinearRegression.cpp"

#include <vector>

int main() {
    std::vector<float> my_v1 = {1, 0, 1, 0, 1, 0};
    std::vector<float> my_v2 = {1,2,2};
    Vector<float> v1(my_v1);
    Vector<float> v2(my_v2);

    std::vector<std::vector<float>> my_m1 {
        {1,1,3},
        {2,5,4},
        {1,2,1},
        {5,6,7},
        {1,3,0},
        {3,2,5}
    };
    std::vector<std::vector<float>> my_m2 {
        {1,2},
        {1,2},
        {1,2}
    };
    Matrix<float> m1(my_m1);
    Matrix<float> m2(my_m2);

    LinearRegression<float> qwe(0.01,0.0);
    qwe.fit(m1, v1, 1000, 1);
    qwe.predict(m1).print();
//    std::cout << res << std::endl;
    return 0;
}