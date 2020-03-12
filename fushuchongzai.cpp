#include  <iostream>
#include  <iomanip>
using  namespace  std;

struct  complex
{
        double  r;
        double  i;
};
complex add(complex c1,complex c2) 
{
        complex c3;
        c3.i =c1.i +c2.i ;
        c3.r =c1.r +c2.r ;
        return c3;

}
complex add(complex c1,double n)
{
	    complex c3;
	    c3.r =c1.r +n;
	    c3.i =c1.i ;
	    return c3; 
}
complex add(double n,complex c1)
{
	    complex c3;
	    c3.r =c1.r +n;
	    c3.i =c1.i ;
	    return c3; 
}

int  main()
{
        double  num;
        complex  a,  b,  c;
        cin  >>  a.r  >>  a.i;
        cin  >>  b.r  >>  b.i;
        cin  >>  num;
        c  =  add(a,  b);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        c  =  add(a,  num);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
        c  =  add(num,  b);
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl;
       
} 
