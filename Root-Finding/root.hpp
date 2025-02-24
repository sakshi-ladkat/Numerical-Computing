#include <iostream>
using namespace std;
class root
{
public:
   double r;

public:
   root()
   {
      r = 0.00;
   }
   pair<double, double> bisectioninterval();
   double bisection(pair<double, double> interval);
   double newtonraphson();
   double fixedpoint();
};