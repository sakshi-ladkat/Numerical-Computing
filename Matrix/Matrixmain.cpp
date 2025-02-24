#include "Matrix.hpp"
using namespace std;

int main()
{
    Matrix matrix1 = Matrix::Input("matrix1.txt");
    Matrix matrix2 = Matrix::Input("matrix2.txt");

    cout << "Matrix 1:" << endl;
    matrix1.Display();
    cout << "\nMatrix 2:" << endl;
    matrix2.Display();

    cout << "Matrix 1 is symmnetric :" << matrix1.isSymmetric() << endl;
    cout << "Matrix 2 is symmnetric :" << matrix2.isSymmetric() << endl;

    cout << "Matrix 1 is Identity :" << matrix1.isIdentity() << endl;
    cout << "Matrix 1 is Identity :" << matrix2.isIdentity() << endl;

    Matrix Add = matrix1.Addition(matrix2);
    std::cout << "\nMatrix Addition" << std::endl;
    Add.Display();

    // Matrix subtraction
    Matrix Sub = matrix1.Subtraction(matrix2);
    cout << "\nMatrix Subtraction" << std::endl;
    Sub.Display();
}