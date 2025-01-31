#include<iostream>
 class cmplx
{
 public:
   double real;
   double img;
   
public :
    cmplx();
   void display();
 cmplx add(cmplx y);
 cmplx sub(cmplx y);
 cmplx conju();
 cmplx div(cmplx y);
 cmplx mul(cmplx y);
 int norm(cmplx y);

};