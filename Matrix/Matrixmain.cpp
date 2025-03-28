#include "Matrix.hpp"
using namespace std;

int main()
{
  Matrix matrix1 = Matrix::Input("matrixA49l.txt");
  Matrix matrix2 = Matrix::Input("matrixb49r.txt");
  Matrix matrix3 = Matrix::Input("matrixA225left.txt");
  Matrix matrix4 = Matrix::Input("matrixb225right.txt");
  Matrix matrix5 = Matrix::Input("matrixSym.txt");
  /*
  cout << "Matrix 1:" << endl;
  matrix1.Display();
  cout << "\nMatrix 2:" << endl;
  matrix2.Display();

  cout << "Matrix 1 is symmnetric :" << matrix1.isSymmetric() << endl;
  cout << "Matrix 2 is symmnetric :" << matrix2.isSymmetric() << endl;

  cout << "Matrix 1 is Identity :" << matrix1.isIdentity() << endl;
  cout << "Matrix 1 is Identity :" << matrix2.isIdentity() << endl;

  Matrix Add = matrix1.Addition(matrix2);
  cout << "\nMatrix Addition" << endl;
  Add.Display();

  // Matrix subtraction
  Matrix Sub = matrix1.Subtraction(matrix2);
  cout << "\nMatrix Subtraction" << endl;
  Sub.Display();


  // Matrix UpperTriangular
  cout << "\n Upper Triangularization" << endl;
  Matrix Upper = matrix1.UpperTriangle();
  Upper.Display();
 */

  // Matrix GaussianElimination (49 X 49 )
  cout << "\nGaussian Elimination" << endl;
  Matrix Answer = matrix1.GaussianElimination(matrix2);
  // cout << "\n L-U Decomposition\n" <<endl;
  //  Answer.Display();

  // LU Decomposition (49 X 49 )
  cout << "\n L-U Decomposition\n"
       << endl;
  Matrix LUsolution = matrix1.LUDecomposition(matrix2);

  /*
      // Matrix GaussianElimination (225 X 225)
      cout << "\nGaussian Elimination" << endl;
      Matrix Answer  = matrix3.GaussianElimination(matrix4);
    // LU Decomposition (225 X 225 )
    cout << "\n L-U Decomposition\n"
         << endl;
    Matrix LUsolution = matrix3.LUDecomposition();
    */
}