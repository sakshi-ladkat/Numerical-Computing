#include "Matrix.hpp"
using namespace std;

Matrix Matrix::LowerTriangular()
{
    if (row != col)
        throw invalid_argument("Matrix Should be squared Matrix");
    Matrix result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            if (i == j)
            
        }
    }
}