#include "Matrix.hpp"
using namespace std;

Matrix Matrix::UpperTriangle()
{
    Matrix result = *this; 

    for (int i = 0; i < row; i++)
    {
        // Partial Pivoting
        int maxRow = i;
        double maxVal = abs(result.values[i][i]);

        for (int k = i + 1; k < row; k++)
        {
            if (abs(result.values[k][i]) > maxVal)
            {
                maxVal = abs(result.values[k][i]);
                maxRow = k;
            }
        }
        if (maxRow != i)
        {
            for (int j = 0; j < col; j++)
            {
                swap(result.values[i][j], result.values[maxRow][j]);
            }
        }

        // Basic Pivoting
        double pivot = result.values[i][i];
        if (pivot == 0)
        {
            continue; 
        }

        // Normalize the pivot row
        for (int j = i; j < col; j++)
        {
            result.values[i][j] /= pivot;
        }

        // Eliminate the elements below the pivot
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