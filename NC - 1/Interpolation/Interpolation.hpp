#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

class Interpolation
{
private:
    int row;
    vector<long double> values;

public:
    Interpolation()
    {
        row = 0;
        values = vector<long double>();
    }
    Interpolation(int r)
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

    Interpolation Input(const string &filepath);
    long double Lagranges(const Interpolation second, double x);
    long double LinearSplines(const Interpolation second, double x);
    void Display() const;
};