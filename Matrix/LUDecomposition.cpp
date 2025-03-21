#include "Matrix.hpp"
using namespace std;

Matrix Matrix::LUDecomposition()
{
    if (this->row != this->col)
        throw runtime_error("Matrix Must Be Square Matrix");

    // Crouts Decomposition
    cout << "LU - Decomposition by Crout's Decomposition" << endl;
    Matrix CroutSolution = this->CroutDecomposition();
    CroutSolution.Display();

    // Do-Littles Decomposition
    cout << "LU - Decomposition by Do-little Decomposition" << endl;
    Matrix DolittleSoultion = this->DolittileDecomposition();
    DolittleSoultion.Display();

    // Choleski Decomposition
    cout << "LU - Decomposition by choleski Decomposition" << endl;
    if (this->isSymmetric())
    {
        Matrix CholeskiSolution = this->CholeskiDecomposition();
        CholeskiSolution.Display();
    }
    else
        throw runtime_error("Matrix Must Be Symmetric ");
}
