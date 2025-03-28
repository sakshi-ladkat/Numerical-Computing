#include "Matrix.hpp"
using namespace std;

Matrix Matrix::createAugmented(const Matrix &second)
{
    if (this->row != second.row)
    {
        throw std::invalid_argument("Matrices must have the same number of rows to create an augmented matrix.");
    }
    Matrix result(this->row, this->col + second.col);

    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            result.values[i][j] = this->values[i][j];
        }
    }

    for (int i = 0; i < second.row; i++)
    {
        for (int j = 0; j < second.col; j++)
        {
            result.values[i][this->col + j] = second.values[i][j];
        }
    }

    return result;
}

Matrix Matrix::Transpose()
{
    Matrix result(col, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.values[j][i] = this->values[i][j];
        }
    }
    return result;
}

Matrix Matrix::LUAugumented(const Matrix &second)
{
    if (this->row != second.row)
    {
        throw invalid_argument("Matrices must have the same number of rows for augmentation.");
    }

    Matrix result(row, col + second.col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.values[i][j] = this->values[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < second.col; j++)
        {
            result.values[i][j + col] = second.values[i][j];
        }
    }

    return result;
}