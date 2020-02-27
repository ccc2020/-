#include <iostream>
#include <cmath>
using namespace std;
int isPrime(unsigned  short n)
{     int i,k=1;
    for( i=2;i<n/2;i++)
      { if(n%i==0) k=0 ;}
        return k;
 }    

int main()
{
    unsigned short a;
    cin>>a;
    if (isPrime(a))
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
}

