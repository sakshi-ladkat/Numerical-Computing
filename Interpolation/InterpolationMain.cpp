#include "Interpolation.hpp"
using namespace std;

int main()
{
    double a;
    cout << "Enter X : ";
    cin >> a;
    Interpolation interp;
    Interpolation x = interp.Input("xi.txt");
    Interpolation y = interp.Input("f(x).txt");
    double answer = x.Lagranges(y, a);
    cout << "F(" << a << ")" << "=" << answer << "\n";

    double answer1 = x.LinearSplines(y, a);
    cout << "F(" << a << ")" << "=" << answer1 << "\n";
    return 0;
}