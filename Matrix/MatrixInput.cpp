#include "Matrix.hpp"
using namespace std;

Matrix Matrix::Input(const string &filepath)
{
    ifstream file(filepath);
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        throw runtime_error("File could not be opened.");
    }
    int rows, cols;
    file >> rows >> cols;

    Matrix matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            file >> matrix.values[i][j];

    file.close();
    return matrix;
}

void Matrix::Display() const
{
    cout << "Matrix (" << row << "x" << col << ")" << endl;
    for (const auto &row : values)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}