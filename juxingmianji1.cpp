#include  <iostream>
using  namespace  std;
class CPoint
{
	friend class CRectangle;
private:
    int x0,y0;
public:
    CPoint(int x,int y);
    CPoint(CPoint &p0); 
};
CPoint::CPoint(int x=0,int y=0)
{
    x0=x;
    y0=y;
    cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &p0)
{
    x0=p0.x0;
    y0=p0.y0;
    cout<<"CPoint copy contstructor is called."<<endl;
}
class CRectangle
{
private:
    CPoint d01,d02;
public:
    CRectangle();
    CRectangle(CPoint d1 ,CPoint d2);
    CRectangle(int x1,int y1,int x2,int y2 );
    CRectangle(CRectangle &p);
    int GetArea();
};
CRectangle::CRectangle():d01(0,0),d02(0,0)
{
  cout<<"CRectangle default contstructor is called."<<endl;
}
CRectangle::CRectangle(CPoint d1 ,CPoint d2):d01(d1),d02(d2)
{
    cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle(int x1,int y1,int x2,int y2 ):d01(x1,y1),d02(x2,y2)
{
    cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &p):d01(p.d01),d02(p.d02)
{
    cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle::GetArea()
{
    int area=0,dx=0,dy=0;
    if(d01.x0>d02.x0)dx=d01.x0-d02.x0;
      else  dx=d02.x0-d01.x0;
    if(d01.y0>d02.y0)dy=d01.y0-d02.y0;
      else  dy=d02.y0-d01.y0;
    area=dx*dy;
    return area;
}
int  main()
{
        int  a=1,  b=1,  c=6,  d=11;
        cout<<"#  Define  p1  ######"<<endl;
        CPoint  p1;
        cout<<"#  Define  p2  ######"<<endl;
        CPoint  p2(10,20);
        cout<<"#  Define  rect1  ######"<<endl;
        CRectangle  rect1;
        cout<<"#  Define  rect2  ######"<<endl;
        CRectangle  rect2(p1,  p2);
        cout<<"#  Define  rect3  ######"<<endl;
        CRectangle  rect3(a,  b,  c,  d);
        cout<<"#  Define  rect4  ######"<<endl;
        CRectangle  rect4(rect2);
        cout<<"#  Calculate  area  ######"<<endl;
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl;
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl;
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl;
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl;
        system("pause");
        return  0;
}
