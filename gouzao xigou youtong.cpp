#include<iostream> 
#include<iomanip>
using namespace std;
const double PI = 3.1415926;
class cylinder
{
	public:
		cylinder(double h1,double r1);
	    double getvolumn();
		double getarea();
		~cylinder();		
	private:
		double r;
		double h;	
};
cylinder::cylinder(double h1,double r1) 
{ 
     cout<<"构造函数被调用"<<endl;
     h=h1;
     r=r1;
}
double cylinder::getvolumn() 
{
	double volumn;
	volumn=PI*r*r*h;
	return volumn;
}
double cylinder::getarea() 
{
	double area;
	area=2*PI*r*h+2*PI*r*r;
	return area;
}
cylinder::~cylinder() 
{
	cout<<"析构函数被调用"<<endl;
}
int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}
