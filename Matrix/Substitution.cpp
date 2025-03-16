#include "Matrix.hpp"
using namespace std;

Matrix Matrix::BackSubstitution()
{
    Matrix solution(row, 1);

    for (int i = row - 1; i >= 0; i--)
    {

        solution.values[i][0] = this->values[i][col - 1];

        for (int j = i + 1; j < row; j++)
        {
            solution.values[i][0] -= this->values[i][j] * solution.values[j][0];
        }

        solution.values[i][0] /= this->values[i][i];
    }

    return solution;
}

Matrix Matrix::ShowSolution()
{
    Matrix solution(row, 1);
    cout << "\nSolution:" << std::endl;
    for (int i = 0; i < row; i++)
    {
        cout << "x" << i + 1 << " = " << this->values[i][0] << std::endl;
    }

    return solution;
}