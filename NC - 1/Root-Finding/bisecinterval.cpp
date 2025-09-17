#include "bisection.cpp"
#include <cmath>
using namespace std;

pair<double, double> root::bisectioninterval()
{
    double a, b;
    bool flag = false;
    for (a = constants::min; a <= constants::max; a++)
    {
        for (b = constants::min; b <= constants::max; b++)
        {
            if ((g(a) * g(b)) < 0)
            {
                flag = true;
            }
            if (flag)
                break;
        }
        if (flag)
            break;
        return {a, b};
    }
}