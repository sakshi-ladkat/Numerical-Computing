#include "Matrix.hpp"
using namespace std;

Matrix Matrix::Addition(const Matrix &second) const
{
    if (row != second.row || col != second.col)
    {
        throw invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            result.values[i][j] = values[i][j] + second.values[i][j];
    return result;
}

Matrix Matrix::Subtraction(const Matrix &second) const
{
    if (row != second.row || col != second.col)
    {
        throw invalid_argument("Matrix dimensions must match for subtraction");
    }
    Matrix result(row, col);
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            result.values[i][j] = values[i][j] - second.values[i][j];
    return result;
}