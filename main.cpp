#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
#include "Math.cpp"
#include "Utils.cpp"
#include "LinearRegression.cpp"
#include "LogisticRegression.cpp"
#include "CSVReader.cpp"

using ComputationType = double;

int main() {
    Matrix<ComputationType> data = CSVReader<ComputationType>::readFile("/Users/svatoslavgladkih/Documents/ml_framework/regression_data.csv", false);
    Matrix<ComputationType> target = CSVReader<ComputationType>::readFile("/Users/svatoslavgladkih/Documents/ml_framework/regression_target.csv", false);
    Matrix<ComputationType> train_data = data;
    Vector<ComputationType> train_target = target.get_ith(0);

//    train_data.print_shape();
//    std::cout << train_target.size() << std::endl;

    LinearRegression<ComputationType> log_reg(0.001, 0.1);
    log_reg.fit(train_data, train_target, 10, 50);


    return 0;
}