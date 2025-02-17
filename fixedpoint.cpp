#include "root.hpp"
#include "constants.hpp"
#include <cmath>
#include <random>
using namespace std;

double q(double x)
{
    return (x * x + 5) / 5;
}

double qfx(double x)
{
    return 2 * x - 5;
}

double q1(double x)
{
    return 2 * sqrt(x - 1);
}

double root::fixedpoint()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(constants::min, constants::max);
    double y = static_cast<double>(dist(gen));
    cout << "y :" << y << endl;
    double yp = y;
    int i = 0;
    cout << "|iteration |       yp       |        y      |" << endl;
    cout << "-------------------------------------------------" << endl;
    do
    {
        yp = y;
        y = q(y);
        cout << "|" << ++i << "        |" << yp << "                |" << y << "        |" << endl;
    } while (fabs(yp - y) > constants::TOL_6 && qfx(y) != 0);
    this->r = y;
    return this->r;
}