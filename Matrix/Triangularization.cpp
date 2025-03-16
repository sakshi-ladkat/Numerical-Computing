#include "Matrix.hpp"
using namespace std;

Matrix Matrix ::UpperTriangle()
{
    Matrix result = *this;
    for (int i = 0; i < row; i++)
    {
        double pivot = result.values[i][i];
        // Basic - Pivoting
        if (pivot == 0)
        {
            for (int k = i + 1; k < row; k++)
            {
                if (result.values[k][i] != 0)
                {
                    for (int j = 0; j < col; j++)
                    {
                        swap(result.values[i][j], result.values[k][j]);
                    }
                    pivot = result.values[i][i];
                    break;
                }
            }
        }
        for (int j = i; j < col; j++)
        {
            result.values[i][j] /= pivot;
        }
        for (int k = i + 1; k < row; k++)
        {
            double factor = result.values[k][i];
            for (int j = i; j < col; j++)
            {
                result.values[k][j] -= factor * result.values[i][j];
            }
        }
    }

    return result;
}