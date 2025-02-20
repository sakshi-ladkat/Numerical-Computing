#include "root.hpp"

int main()
{
     root ans;
     std::pair<double, double> interval = ans.bisectioninterval();
     cout << "---------------------------------------------------------------" << endl;
     cout << "bisection Method" << endl;
     cout << "--------------------------------------------------------------" << endl;
     cout << "root = " << ans.bisection(interval) << endl
          << endl;

     cout << "---------------------------------------------------" << endl;
     cout << "Fixed point Method" << endl;
     cout << "---------------------------------------------------" << endl;
     cout << "root= " << ans.fixedpoint() << endl
          << endl;

     cout << "---------------------------------------------------" << endl;
     cout << "Newton-Raphson point Method" << endl;
     cout << "---------------------------------------------------" << endl;
     cout << "root =" << ans.newtonraphson() << endl
          << endl;
}