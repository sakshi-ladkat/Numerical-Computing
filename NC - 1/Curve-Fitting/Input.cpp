#include "Curve.hpp"
using namespace std;

Curve Curve::Input(const string &filepath)
{
    ifstream file(filepath);
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        throw runtime_error("File could not be opened.");
    }

    int rows;
    file >> rows;

    Curve curve(rows);

    for (int i = 0; i < rows; i++)
    {
        long double val;
        file >> val;
        curve.setValue(i, val);
    }

    file.close();
    return curve;
}

void Curve::Display() const
{
    cout << "Interpolation Vector (" << row << " rows):" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << values[i] << "\n";
    }
}