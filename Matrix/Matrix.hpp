#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    vector<vector<long double>> values;

public:
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        values = vector<vector<long double>>(r, vector<long double>(c, 0));
    }
    static Matrix Input(const string &filepath);
    void Display() const;
    bool isSymmetric() const;
    bool isIdentity() const;
    bool isDiagonallyDominant() const;
    Matrix Addition(const Matrix &second) const;
    Matrix Subtraction(const Matrix &second) const;
    Matrix Transpose();
    Matrix UpperTriangle();
    Matrix createAugmented(const Matrix &second);
    Matrix GaussianElimination(const Matrix &second);
    Matrix GaussJacobi(const Matrix &second);
    Matrix GaussSiedel(const Matrix &second);
    Matrix ForwardSubstitution();
    Matrix BackSubstitution();
    Matrix ShowSolution();
    Matrix LUDecomposition(const Matrix &second);
    Matrix IterativeMethod(const Matrix &second);
    Matrix CroutDecomposition(const Matrix &second);
    Matrix DolittileDecomposition(const Matrix &second);
    Matrix CholeskiDecomposition(const Matrix &second);
    Matrix LUAugumented(const Matrix &second);
    Matrix MakeDiagonalDominant();

    //~Matrix();
};