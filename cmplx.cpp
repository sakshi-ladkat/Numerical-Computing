#include "cmplx.hpp"
#include<math.h>
using namespace std;

//constructot 
cmplx::cmplx()
{
    real=0;
    img=0;
}

void cmplx::display()
{
    if( img < 0 )
    {
        cout << real<<img <<"i"<<std::endl;
    }
    else
    {
        cout << real<<"+"<<img <<"i"<<std::endl;
    }

}

cmplx cmplx::add (cmplx y)
{
    cmplx c;
    c.real = this->real + y.real;
    c.img = this->img + y.img;
    
    return c;
}

cmplx cmplx::sub (cmplx y)
{
    cmplx c;
    c.real = this->real - y.real;
    c.img = this->img - y.img;
 
    return c;
}

cmplx cmplx:: conju ()
{
    cmplx c;
    if(c.img < 0 )
    {
        c.real = this->real;
        c.img  = +(this->img);
    }
    else
    {
        c.real = this->real;
        c.img  = -(this->img);
    }
    return c;
}

int cmplx :: norm(cmplx y)
{
        int r;
        r = sqrt((y.real*y.real)+(y.img*y.img));
        cout<<r;
}

cmplx cmplx :: mul(cmplx y)
{
    cmplx c;
    c.real= this->real*y.real;
    c.img = (this->real*y.img)+(this->img*y.real)+(this->img*y.img);
    return c;
}

cmplx cmplx :: div(cmplx y)
{
    cmplx c;
    c.real = ((this->real*y.real)+(this->img*y.img))/((y.real*y.real)+(y.img*y.img));
    c.img  = ((this->img*y.real)-(this->real*y.img))/((y.real*y.real)+(y.img*y.img));
    return c;
}