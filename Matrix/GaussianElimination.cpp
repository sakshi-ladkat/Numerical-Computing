#include "Matrix.hpp"
using namespace std;

Matrix Matrix ::GaussianElimination(const Matrix &second)
{
    // Creates Augumented Matrix
    Matrix Augumented = this->createAugmented(second);
    // Upper Matrix Triangularization
    Matrix Upper = Augumented.UpperTriangle();
    cout << "\n Upper Triangular Matrix" << endl;
    // Display Upper Triangular Matrix
    Upper.Display();
    // Back Substitution
    Matrix solution = Upper.BackSubstitution();
    // Printing solution
    solution.ShowSolution();
    return solution;
}
