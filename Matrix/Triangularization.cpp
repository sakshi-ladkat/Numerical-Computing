#include "Matrix.hpp"
using namespace std;

int Matrix::Swapindex(int i)
{
    for (int k = i + 1; k < row; k++)
    {
        if (this->values[k][i] != 0)
            return k;
    }
    return -1;
}

void Matrix ::SwapRows(int row1, int row2)
{
    if (row1 == row2)
        return;
    swap(this->values[row1], this->values[row2]);
}

Matrix Matrix::NUpperTriangular()
{
    if (row != col)
        throw invalid_argument("Matrix Should be squared Matrix");
}

Matrix Matrix::BUpperTriangular()
{

    Matrix result(*this);
    for (int i = 0; i < row; i++)
    {
        if (result.values[i][i] == 0)
        {
            int k = result.Swapindex(i);
            if (k == -1)
                continue;
            result.SwapRows(i, k);
        }
        for (int j = i + 1; j < row; j++)
        {
            int factor = result.values[i + 1][j];
            result.values[i][j] = 1;
            for (int k = i; k < col + 1; j++)
            {
                if (k > j && result.values[j][i] != 0)
                    result.values[j][i] = 0;
                if (k < j && result.values[i][j] != 0)
                    result.values[i + 1][j] -= factor * result.values[i][j];
            }
        }
    }
    return result;
}
