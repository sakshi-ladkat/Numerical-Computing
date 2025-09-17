#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

class Curve
{

private:
    int row;
    vector<long double> values;

public:
    Curve()
    {
        row = 0;
        values = vector<long double>();
    }

    Curve(int r)
    {
        row = r;
        values = vector<long double>(r, 0);
    }

    // Getters And Setters
    void setValue(int index, long double val)
    {
        if (index >= 0 && index < row)
            values[index] = val;
    }

    long double getValue(int index) const
    {
        if (index >= 0 && index < row)
            return values[index];
        return 0;
    }

    long double &operator[](int index)
    {
        return values[index];
    }

    static Curve Input(const string &filepath);
    double LeastSquare(const Curve second);
    double LeastSquareParabola(const Curve second);
    double LeastSquareExponential(const Curve second);
    double LeastSquarePowerFit(const Curve second);
    void Display() const;
};