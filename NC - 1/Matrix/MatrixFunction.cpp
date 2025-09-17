#include "Matrix.hpp"
using namespace std;

Matrix Matrix::createAugmented(const Matrix &second)
{
    if (this->row != second.row)
    {
        throw invalid_argument("Matrices must have the same number of rows to create an augmented matrix.");
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

Matrix Matrix::MakeDiagonalDominant()
{
    Matrix result = *this;

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            if (i != j)
                sum += abs(result.values[i][j]);
        }
        if (abs(result.values[i][i]) < sum)
        {
            bool swapped = false;
            for (int k = i + 1; k < row; k++)
            {
                int rowSum = 0;
                for (int l = 0; l < col; l++)
                {
                    if (l != i)
                        rowSum += abs(result.values[k][l]);
                }
                if (abs(result.values[k][k]) >= rowSum)
                {
                    swap(result.values[i], result.values[k]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped)
                cout << "Cannot make the matrix diagonally dominant.Continue without diagonal dominance";
        }
    }
    return result;
}
