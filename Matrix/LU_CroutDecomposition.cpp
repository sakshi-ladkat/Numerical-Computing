#include "Matrix.hpp"
using namespace std;

Matrix Matrix::CroutDecomposition()
{
    Matrix result(*this);
    Matrix L(row, col);
    Matrix U(row, col);
    // Initializing Diagonal U[i][i]=1
    for (int i = 0; i < row; i++)
    {
        U.values[i][i] = 1;
    }
    // Crout's Decomposition
    for (int j = 0; j < col; j++)
    {
        for (int i = j; i < row; i++)
        {
            double sum = 0;
            for (int k = 0; k < j; k++)
            {
                sum += L.values[i][k] * U.values[k][j];
            }
            L.values[i][j] = result.values[i][j] - sum;
        }

        for (int i = j + 1; i < row; i++)
        {
            double sum = 0;
            for (int k = 0; k < j; k++)
            {
                sum += L.values[j][k] * U.values[k][i];
            }
            U.values[j][i] = (result.values[j][i] - sum) / L.values[j][j];
        }
    }

    Matrix Solution = L.LUAugumented(U);
    return Solution;
}