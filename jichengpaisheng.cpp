#include  <iostream> 
using  namespace  std; 
const  float  pi=3.14159; 
class Shape
{
	private:
		int m_ID;
	public:
    	int getter(){return m_ID;}
    	void setter(int val){m_ID=val;}
    	int getArea(){return 0;}
    	Shape(int ID){m_ID=ID;cout<<"Shape constructor called:"<<m_ID<<endl;}
    	~Shape(){cout<<"Shape destructor called:"<<m_ID<<endl;	}
};
class Circle:public Shape
{
	private:
		int r;
	public:
    	int getter(){return r;}
    	void setter(int val){r=val;}
   	    float getArea(){return pi*r*r;}
   	    Circle(int i,int j);
        ~Circle();
};
Circle::Circle(int i,int j):Shape(j)
{
	r=i;
	cout<<"Circle constructor called:"<<Shape::getter()<<endl;
}
Circle::~Circle()
{
	cout<<"Circle destructor called:"<<Shape::getter()<<endl;
}
class Rectangle:public Shape
{
	private:
		int h,w;
	public:
    	int getterh(){return h;}
    	void setterh(int val){h=val;}
        int getterw(){return w;}
        void setterw(int val){w=val;}
        int getArea(){return h*w;}
        Rectangle(int i,int j,int k);
        ~Rectangle();
};
Rectangle::Rectangle(int i,int j,int k):Shape(k)
{
	h=i;
	w=j;
	cout<<"Rectangle constructor called:"<<Shape::getter()<<endl;
}
Rectangle::~Rectangle()
{
	cout<<"Rectangle destructor called:"<<Shape::getter()<<endl;
}
int  main() 
{ 
        Shape  s(1);//1��ʾID 
        Circle  c(4,2);//4��ʾ�뾶��2��ʾID 
        Rectangle  r(4,5,3);//4��5��ʾ���Ϳ�3��ʾID 
        cout<<"Shape�����"<<s.getArea()<<endl; 
        cout<<"Circle�����"<<c.getArea()<<endl; 
        cout<<"Rectangle�����"<<r.getArea()<<endl; 
}


