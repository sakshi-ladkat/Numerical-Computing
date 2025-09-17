#include "Interpolation.hpp"
using namespace std;

long double Interpolation::Lagranges(const Interpolation second, double x)
{
    if (row != second.row)
        throw invalid_argument("X and Y vectors must be of same size");

    long double result = 0.0;
    for (int i = 0; i < row; i++)
    {
        long double Answer = second.values[i];
        for (int j = 0; j < row; j++)
        {
            if (i != j)
            {
                Answer *= (x - this->values[j]) / (this->values[i] - this->values[j]);
            }
        }
        result += Answer;
    }
    return result;
}