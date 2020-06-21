#include  <iostream> 
using  namespace  std; 
class Point
{
	public:
		Point(int x=0,int y=0){	m_x=x;	m_y=y;}//构造函数 
		Point operator ++();//前置单目运算符重载 
		Point operator ++(int);//后置单目运算符重载 
		friend ostream & operator <<(ostream &output,Point p);
		
	private:
		int m_x,m_y;	
};

Point Point::operator ++()
{
	m_x++;
	m_y++;
	return *this;
}
Point Point::operator ++(int)
{
    Point old=*this;
    ++(*this);
    return old;
}
ostream  & operator <<(ostream &output,Point p)
{
	output<<"("<<p.m_x<<","<<p.m_y<<")"<<endl;
	return output;
}
int  main() 
{ 
        Point  a(1,3); 
        cout<<a; 
        cout<<a++; 
        cout<<++a; 
        return  0; 
}

