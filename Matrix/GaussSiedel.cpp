#include "Matrix.hpp"
using namespace std;

Matrix Matrix::GaussSiedel(const Matrix &second)
{

    if (this->row != second.row && this->col != second.col)
    {
        throw invalid_argument("Matrices must have the same number of rows and columns");
    }
    double tolerance = 1e-6;
    bool converged = false;
    Matrix solution(row, 2);
    for (int i = 0; i < row; i++)
    {
        solution.values[i][0] = 0.0; // previous values
        solution.values[i][1] = 0.0; // current  values
    }
    while (!converged)
    {
        converged = true;
        for (int i = 0; i < row; i++)
        {
            double sum = second.values[i][0];
            for (int j = 0; j < col; j++)
            {
                if (j != i)
                {
                    if (j < i)
                        sum += (-1) * this->values[i][j] * solution.values[j][1];
                    else
                        sum += (-1) * this->values[i][j] * solution.values[j][0];
                }
            }
            solution.values[i][1] = sum / this->values[i][i];

            if (fabs(solution.values[i][1] - solution.values[i][0]) > tolerance)
            {
                converged = false;
            }
        }
        for (int i = 0; i < row; i++)
        {
            solution.values[i][0] = solution.values[i][1];
        }
    }
    Matrix result(row, 1);
    for (int i = 0; i < row; i++)
    {
        result.values[i][0] = solution.values[i][1];
    }

    return result;
}