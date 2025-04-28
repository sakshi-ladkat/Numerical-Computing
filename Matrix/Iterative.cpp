#include "Matrix.hpp"
using namespace std;
Matrix Matrix::IterativeMethod(const Matrix &second)
{
    if (this->row != second.row && this->col != second.col)
    {
        throw invalid_argument("Matrices must have the same number of rows and columns");
    }

    int a;
    cout << "1. Gauss Jacobi\n2. Gauss Seidel\nEnter your choice: ";
    cin >> a;

    Matrix solution(row, 1);

    switch (a)
    {
    case 1:
        if (!this->isDiagonallyDominant())
        {
            this->MakeDiagonalDominant();
        }
        solution = this->GaussJacobi(second);
        break;

    case 2:
        if (!this->isDiagonallyDominant())
        {
            this->MakeDiagonalDominant();
        }
        solution = this->GaussSiedel(second);
        break;

    default:
        cout << "Invalid Choice";
        throw invalid_argument("Invalid iterative method choice");
    }

    solution.ShowSolution();
    return solution;
}
