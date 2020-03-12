#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;
const  double  PI=3.1415926;
//请在此处完善类的设计
class cylinder
{
	public:
		void init(double r1,double h1);
		double getvolumn();
		double getarea();
	private:
		double r,h;
};
void cylinder::init(double h1,double r1)
{
	r=r1;
	h=h1;
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

int  main()
{
        double  d,h;
        cin>>d>>h;
        cylinder can;
        can.init(h,d/2);
        cout<<fixed<<setprecision(6);
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl;
        cout<<"铁皮的面积是"<<can.getarea()<<endl;
}

