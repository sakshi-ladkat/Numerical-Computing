#include "Interpolation.hpp"
using namespace std;

Interpolation Interpolation::Input(const string &filepath)
{
    ifstream file(filepath);
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        throw runtime_error("File could not be opened.");
    }

    int rows;
    file >> rows;

    Interpolation interpolation(rows);

    for (int i = 0; i < rows; i++)
    {
        long double val;
        file >> val;
        interpolation.setValue(i, val);
    }

    file.close();
    return interpolation;
}

void Interpolation::Display() const
{
    cout << "Interpolation Vector (" << row << " rows):" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << values[i] << "\n";
    }
}