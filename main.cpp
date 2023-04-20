#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
#include "Math.cpp"
#include "Utils.cpp"
#include "LinearRegression.cpp"
#include "LogisticRegression.cpp"
#include "CSVReader.cpp"

using ComputationType = float;

int main() {
    Matrix<ComputationType> data = CSVReader<ComputationType>::readFile("/Users/svatoslavgladkih/Documents/ml_framework/classification_data.csv", false, false);
    Matrix<int> target = CSVReader<int>::readFile("/Users/svatoslavgladkih/Documents/ml_framework/classification_target.csv", false, true);
    Matrix<ComputationType> train_data = data;
    Vector<int> train_target = target.get_ith(0);

//    train_data.print_shape();
//    std::cout << train_target.size() << std::endl;

    LogisticRegression<ComputationType> model(0.01, 0.1);
    model.fit(train_data, train_target, 1, 1);


    return 0;
}