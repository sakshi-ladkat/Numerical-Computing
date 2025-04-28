#include "Curve.hpp"
#include <iostream>
using namespace std;

int main()
{

    Curve x = Curve::Input("xi.txt");
    Curve y = Curve::Input("f(x).txt");
    int choice;
    cout << "Select the curve fitting method:\n";
    cout << "1. Linear Fit (y = a + bx)\n";
    cout << "2. Parabola Fit (y = a + bx + cx^2)\n";
    cout << "3. Exponential Fit (y = c * e^(ax))\n";
    cout << "4. Power Fit (y = A * x^b)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    double result;

    switch (choice)
    {
    case 1:
        result = x.LeastSquare(y);
        break;
    case 2:
        result = x.LeastSquareParabola(y);
        break;
    case 3:
        result = x.LeastSquareExponential(y);
        break;
    case 4:
        result = x.LeastSquarePowerFit(y);
        break;
    default:
        cout << "Invalid choice.\n";
        return 1;
    }

    cout << "\nRMS Error from the selected fit: " << result << endl;

    return 0;
}