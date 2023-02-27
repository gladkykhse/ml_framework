#include <iostream>
#include "Matrix.cpp"
#include <vector>

int main() {
    std::vector<std::vector<int>> my_matrix1 {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    std::vector<std::vector<int>> my_matrix2 {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    Matrix<int> matrix1(my_matrix1);
    Matrix<int> matrix2(my_matrix2);
    Matrix<int> newMatrix = matrix1 + matrix2;
    (matrix1 + 2.0).print();
    (matrix1 - 2).print();
    (matrix1 * 2).print();
    (matrix1 / 0).print();
    return 0;
}