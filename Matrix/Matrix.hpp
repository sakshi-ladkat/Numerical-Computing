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
    Matrix Addition(const Matrix &second) const;
    Matrix Subtraction(const Matrix &second) const;
    Matrix Transpose();
    Matrix UpperTriangle();
    Matrix createAugmented(const Matrix &second);
    Matrix GaussianElimination(const Matrix &second);
    Matrix BackSubstitution();
    Matrix ShowSolution();
    Matrix LUDecomposition();
    Matrix CroutDecomposition();
    Matrix DolittileDecomposition();
    Matrix CholeskiDecomposition();
    Matrix LUAugumented(const Matrix &second);

    //~Matrix();
};