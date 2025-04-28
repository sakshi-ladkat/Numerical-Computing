#include "Matrix.hpp"
using namespace std;

int main()
{
     Matrix matrix1 = Matrix::Input("matrixA49l.txt");
     Matrix matrix2 = Matrix::Input("matrixb49r.txt");
     Matrix matrix3 = Matrix::Input("matrixA225left.txt");
     Matrix matrix4 = Matrix::Input("matrixb225right.txt");
     Matrix matrix5 = Matrix::Input("matrixSym.txt");
     Matrix matrix6 = Matrix::Input("matrixsym1.txt");
     Matrix matrix7 = Matrix::Input("matrix_A.txt");
     Matrix matrix8 = Matrix::Input("matrix_B.txt");

     // Displaying Matrix
     cout << "Matrix 1:" << endl;
     matrix1.Display();
     cout << "\nMatrix 2:" << endl;
     matrix2.Display();

     // Checking if Matrix is symmetric
     cout << "Matrix 1 is symmnetric :" << matrix1.isSymmetric() << endl;
     cout << "Matrix 2 is symmnetric :" << matrix2.isSymmetric() << endl;

     // Checking if Matrix is Identity
     cout << "Matrix 1 is Identity :" << matrix1.isIdentity() << endl;
     cout << "Matrix 1 is Identity :" << matrix2.isIdentity() << endl;

     // Matrix Addition
     Matrix Add = matrix7.Addition(matrix8);
     cout << "\nMatrix Addition" << endl;
     Add.Display();

     // Matrix subtraction
     Matrix Sub = matrix7.Subtraction(matrix8);
     cout << "\nMatrix Subtraction" << endl;
     Sub.Display();

     // Matrix UpperTriangular
     cout << "\n Upper Triangularization" << endl;
     Matrix Upper = matrix1.UpperTriangle();
     Upper.Display();

     // Matrix GaussianElimination (49 X 49 )
     cout << "\nGaussian Elimination" << endl;
     matrix1.GaussianElimination(matrix2);

     // Matrix GaussianElimination (225 X 225 )
     cout << "\nGaussian Elimination" << endl;
     matrix3.GaussianElimination(matrix4);

     // L-U Decomposition (49 X 49 )
     cout << "\nL-U Decomposition" << endl;
     matrix1.LUDecomposition(matrix2);

     // L-U Decomposition (225 X 225 )
     cout << "\nL-U Decomposition" << endl;
     matrix3.LUDecomposition(matrix4);

     // Iterative Method (49 X 49)
     cout << "\nIterative Method" << endl;
     matrix1.IterativeMethod(matrix2);
     return 0;

     // Iterative Method (225 X 225)
     cout << "\nIterative Method" << endl;
     matrix3.IterativeMethod(matrix4);
     return 0;
}