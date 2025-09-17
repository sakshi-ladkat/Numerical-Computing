#include "Matrix.hpp"
using namespace std;

Matrix Matrix::DolittileDecomposition(const Matrix &second)
{

    Matrix L(row, col);
    Matrix U(row, col);
    Matrix result(*this);

    // Initialize L[i][i]=1
    for (int i = 0; i < row; i++)
    {
        L.values[i][i] = 1;
    }

    // Doolittle's LU Decomposition
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i <= j)
            {
                // Calculate U[i][j]
                double sum = 0;
                for (int k = 0; k < i; k++)
                {
                    sum += L.values[i][k] * U.values[k][j];
                }
                U.values[i][j] = result.values[i][j] - sum;
            }
            else
            {
                // Calculate L[i][j]
                double sum = 0;
                for (int k = 0; k < j; k++)
                {
                    sum += L.values[i][k] * U.values[k][j];
                }
                L.values[i][j] = (result.values[i][j] - sum) / U.values[j][j];
            }
        }
    }
   /*
    Matrix Solution = L.LUAugumented(U);
    return Solution;
    */
    Matrix y = L.createAugmented(second);
    Matrix z = y.ForwardSubstitution();
    Matrix x = U.createAugmented(z);
    Matrix Solution = x.BackSubstitution();
    return Solution;
}