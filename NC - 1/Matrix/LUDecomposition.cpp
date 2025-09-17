#include "Matrix.hpp"
using namespace std;

Matrix Matrix::LUDecomposition(const Matrix &second)
{
    if (this->row != this->col)
        throw runtime_error("Matrix Must Be Square Matrix");
    int a;
    cout << "1.LU - Decomposition by Crout's Decomposition \n2.LU -Decomposition by Do - little Decomposition\n3.LU - Decomposition by Choleski Decomposition\n Enter your choice :";
    cin >> a;
    Matrix Solution(row, 1);
    switch (a)
    {
    case 1:
        // Crouts Decomposition
        Solution = this->CroutDecomposition(second);
        break;

    case 2:
        // Do-Littles Decomposition
        Solution = this->DolittileDecomposition(second);
        break;

    case 3:
        // Choleski Decomposition
        cout << "LU - Decomposition by Choleski Decomposition" << endl;
        try
        {
            if (!this->isSymmetric())
            {
                throw std::invalid_argument("Matrix must be symmetric.");
            }

            Solution = this->CholeskiDecomposition(second);
        }
        catch (const std::invalid_argument &e)
        {
            cout << "Skipping Choleski Decomposition: " << e.what() << endl;
        }
        break;
    default:
        cout << "Invalid choice";
    }
    Solution.ShowSolution();
    return Solution;
}
