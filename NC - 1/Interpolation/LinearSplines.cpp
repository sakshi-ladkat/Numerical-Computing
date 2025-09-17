#include "Interpolation.hpp"
using namespace std;

long double Interpolation::LinearSplines(const Interpolation second, double x)
{
    if (row != second.row)
        throw invalid_argument("X and Y vectors must be of same size");

    long double result = 0.0;
    for (int i = 0; i < row; i++)
    {
        if (x >= this->values[i] && x <= this->values[i + 1])
        {
            cout << "x is outside the interpolation range";
            return NAN;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < row - 1; i++)
    {
        if (x >= this->values[i] && x <= this->values[i + 1])
        {
            for (int j = i; j <= i + 1; j++)
            {
                long double Answer = second.values[i];
                {
                    if (i != j)
                        Answer *= (x - this->values[j]) / (this->values[i] - this->values[j]);
                }
                result += Answer;
            }
        }
    }
    return result;
}
