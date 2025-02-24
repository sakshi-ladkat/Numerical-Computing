#include "root.hpp"
#include "constants.hpp"
#include <cmath>
#include <random>
using namespace std;

double f(double x)
{
    return x * x - 5 * x + 5;
}
double dfx(double x)
{
    return 2 * x - 5;
}

double root::newtonraphson()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(constants::min, constants::max);
    double y = static_cast<double>(dist(gen));
    cout << "y :" << y << endl;
    double yp = y;
    int i = 0;
    cout << "|iteration |       x       |        y      |" << endl;
    cout << "-------------------------------------------------" << endl;
    do
    {
        yp = y;
        y = yp - (f(y) / dfx(y));
        cout << "|" << ++i << "        |" << yp << "                |" << y << "        |" << endl;
    } while (abs(yp - y) > constants::TOL_6 && dfx(y) != 0);

    this->r = y;
    return this->r;
}