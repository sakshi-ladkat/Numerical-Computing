#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Matrix
{

private:
    int row;
    int col;
    vector<vector<int>> values;

public:
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        values.vector<(r, vector<int>(c))>;
    }
    static Matrix Input(const string &filepath);
    void Display() const;
    bool isSymmetric() const;
    bool isIdentity() const;
    Matrix Addition(const Matrix &second) const;
    Matrix Subtraction(const Matrix &second) const;

    //~Matrix();
};