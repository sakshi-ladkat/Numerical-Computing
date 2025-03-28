#include "Matrix.hpp"
#include <math.h>
using namespace std;

Matrix Matrix::CholeskiDecomposition(const Matrix &second)
{
    Matrix L(row, col);
    Matrix result(*this);

    // Choleski Factorization
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (1 < i <= col)
            {
                double sum = 0;
                for (int k = 1; k < j; k++)
                {
                    sum += L.values[i][k] * L.values[k][j];
                }
                L.values[i][i] = (result.values[i][j] - sum) / L.values[i][i];
            }
            else if (i > j)
            {
                double sum = 0;
                for (int k = 0; k < i; k++)
                {

                    sum += L.values[i][k] * L.values[i][k];
                }
                L.values[i][j] = sqrt(result.values[i][j] - sum);
            }
        }
    }

    Matrix U = L.Transpose();
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