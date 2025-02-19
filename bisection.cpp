#include "root.hpp"
#include "constants.hpp"
#include <cmath>
using namespace std;

double g(double x)
{
    return x * x - 5 * x + 5;
}

double root::bisection(pair<double, double> interval)
{
    // pair<double, double> interval = this->bisection();
    double a = interval.first;
    double b = interval.second;

    if (!((g(a) * g(b)) < 0))
        cout << "Could not find any root in interval (" << constants::min << "," << constants::max << ")" << endl;
    ;
    int i = 0;
    double x = 0;
    double xp = 1;
    cout << "|iteration |      a        |       b      |       f(a)     |        f(b)     |       x     |        f(x)    | " << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    while (abs(xp - x) > constants::TOL_6)
    {
        xp = x;
        x = (a + b) / 2;
        cout << "|" << ++i << "|      " << a << "     |      " << b << "     |     " << g(a) << "    |    " << g(b) << "     |    " << x << "    |    " << g(x) << "       |" << endl;
        if ((g(x) * g(a)) < 0)
            b = x;
        if ((g(x) * g(b)) < 0)
            a = x;
    }
    this->r = x;
    return this->r;
}