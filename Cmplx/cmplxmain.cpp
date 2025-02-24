#include "cmplx.hpp"
using namespace std;
int main()
{
    cmplx p,q,ans;
    int norm;

    p.real=10.00;
    p.img=-12.00;
    q.real=20.00;
    q.img=13.00;

    cout<< "p = ";
    p.display();

    cout<<"q = ";
    q.display();

    ans = p.add(q);
    cout<< "Addition = ";
    ans.display();

    ans=p.sub(q);
    cout<< "subtraction = ";
    ans.display();
   
    ans=p.conju();
    cout<<"conjugate = ";
    ans.display();

    ans=p.mul(q);
    cout<<"Multiplication = ";
    ans.display();

    ans=p.div(q);
    cout<<"Division = ";
    ans.display();

    cout<<"Norm = ";
    norm=p.norm(q);
   
}