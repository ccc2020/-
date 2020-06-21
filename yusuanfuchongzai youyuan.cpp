#include  <iostream> 
using  namespace  std; 
class  Complex
{
	public:
		Complex(double r=0.0,double i=0.0){real=r;imag=i;}//构造函数 
		friend Complex operator +(Complex c1,Complex c2);//+重载为友元函数 
		friend Complex operator -(Complex c1,Complex c2);//-重载为友元函数 
		void print();//输出复数
	private:
	    double real;
		double imag;  
};
Complex operator +(Complex c1,Complex c2)
{
	
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator -(Complex c1,Complex c2)
{

	return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
void Complex::print()
{
	cout<<"("<<real<<")"<<"+("<<imag<<"i)"<<endl;
}
int  main() 
{ 
        Complex  a(3,4),b(1,-1),c; 
        c=a+b; 
        cout<<"a+b="; 
        c.print(); 
        cout<<endl; 
        c=a-b; 
        cout<<"a-b="; 
        c.print(); 
        cout<<endl; 
        c=a+100; 
        cout<<"a+100="; 
        c.print(); 
        cout<<endl; 
        c=a-2.5; 
        cout<<"a-2.5="; 
        c.print(); 
        cout<<endl; 

        return  0; 
} 
