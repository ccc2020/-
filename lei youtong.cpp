#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;
const  double  PI=3.1415926;
//���ڴ˴�����������
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
        cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<"  "<<endl;
        cout<<"��Ƥ�������"<<can.getarea()<<endl;
}

