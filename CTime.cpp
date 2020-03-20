#include <iostream>
#include <cmath>
using namespace std;
int leapyear(int n)
{
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        return 1;
    else
        return 0;
}
class CTime
{
public:
    CTime(int year1, int month1, int day1, int hour1, int minute1, int second1);
    CTime(CTime &p);
    int dayDiff(CTime h);
    void showTime();
    int isvalid();
    ~CTime();
    void isvalid0();

private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

CTime::CTime(int year1, int month1, int day1, int hour1 = 0, int minute1 = 0, int second1 = 0)
{   
    
	    year = year1;
        month = month1;
        day = day1;
        hour = hour1;
        minute = minute1;
        second = second1;
        isvalid0();
		   

}
CTime::~CTime()
{
    cout << "析构函数被调用" << endl;
}
CTime::CTime(CTime &p)
{
    cout << "拷贝构造函数被调用" << endl;
    year = p.year;
    month = p.month;
    day = p.day;
    hour = p.hour;
    minute = p.minute;
    second = p.second;
}
void CTime::isvalid0() //判断函数
{

    int k, d = 1, t=0;
    //判断是否是闰年 k=1是闰年<
    if (leapyear(year))
        k = 1;
    else
        k = 0;
    // 判断是否是闰年 k=0不是闰年>
    //分月份判断日期是否合法<
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31 || day < 1)
        {
            d = 0;
            year = 0;
            month = 0;
            day = 0;
            hour = 0;
            minute = 0;
            second = 0;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30 || day < 1)
        {
            d = 0;
            year = 0;
            month = 0;
            day = 0;
            hour = 0;
            minute = 0;
            second = 0;
        }
    }

    if(month==2)
    {
        if (k == 1)
        {
            if (day > 29 || day < 1)
            {
                d = 0;
                year = 0;
                month = 0;
                day = 0;
                hour = 0;
                minute = 0;
                second = 0;
            }
        }
        if (k == 0)
        {
            if (day > 28 || day < 1)
            {
                d = 0;
                year = 0;
                month = 0;
                day = 0;
                hour = 0;
                minute = 0;
                second = 0;
            }
        }
    }
    //分月份判断日期是否合法>
    // 判断时间是否合法<
    if ((hour < 24) && (hour >= 0) && (minute <= 59) && (minute >= 0) && (second <= 59) && (second >= 0))
        t = 1;
    else
    {
        t = 0;
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        second = 0;
    }
    //判断时间是否合法>   
    if(d!= 0&&t!=0) cout<<"构造函数被调用"<<endl;
    if(d==0&&t!=0)  {cout<<"date error!"<<endl;cout<<"构造函数被调用"<<endl;}
    if(d!=0&&t==0)  {cout<<"time error!"<<endl;cout<<"构造函数被调用"<<endl;}
    if(d==0&&t==0)  {cout<<"date and time error!"<<endl;cout<<"构造函数被调用"<<endl;}
}
int CTime::isvalid()
{
	if(year!=0) return 1;
	else      return 0;	
}
void CTime::showTime()
{        
        cout << year << "/" << month << "/" << day << " " << hour << ":" << minute << ":" << second << endl;
}

int CTime::dayDiff(CTime h)
{
    int d = 0, n, d1 = 0, d2 = 0, d3 = 0, d4 = 0;
    int amonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year != 0)
    {
        if (leapyear(year))
        {
            if (year >h.year)
            {
                n = (year - h.year) / 4;
                d1 = n * 366;
                d2 = (year - h.year - n) * 365;
                if(month>h.month)
                 {
				  for (int i = h.month; i < month; i++)
                     d3 = d3 + amonth[i];
                  d3 = d3 + 1;
                  d4 = abs(day - h.day);
                 }
                else if(month==h.month)
                {
                	if(day>h.day)d4=h.day-day;
                  	else d4=day-h.day;
				}
                else
                 {
                 	for(int i=h.month;i<12;i++)
                 	  d3=d3+ amonth[i];
                 	for(int i=0;i<month;i++)
                 	  d3=d3+ amonth[i];
					    d3 = d3 + 1;
                d4 = abs(day - h.day);
				 }
               
                d = d1 + d2 + d3 + d4;
            }
            else if(year==h.year)
            {
            	if(month>=h.month)
				{ 
				    for (int i = h.month; i < month; i++)
                     d3 = d3 + amonth[i];
                    d3=d3+1;
                    d4 = abs(day - h.day);
                    d = d1 + d2 + d3 + d4;
				}
				else
				{
					for(int i=month;i<h.month;i++)
					 d3 = d3 + amonth[i];
					 d3=d3+1;
					 d4 = abs(day - h.day);
                    d = d1 + d2 + d3 + d4;
				}
			}
            else
            {
                n=(h.year-year)/4;
                d1=n * 366;
                d2=(h.year-year-n)*365;
                if(h.month>=month)
                  {	
				    for(int i=month;i<h.month;i++)
                     d3=d3+amonth[i];
                  }
                else
                 {
                 	for(int i=month;i<12;i++)
                 	   d3=d3+ amonth[i];
                 	for(int i=0;i<h.month;i++)
                 	    d3=d3+ amonth[i];
				 }
                d3=d3+1;
                d4=abs(h.day-day);
                d=d1 + d2 + d3 + d4;
            }
        }
        else
        {
            if (year >= h.year)
            {
                n = (year - h.year) / 4;
                d1 = n * 366;
                d2 = (year - h.year - n) * 365;
                if(month>=h.month)
                 {
				  for (int i = h.month; i < month; i++)
                     d3 = d3 + amonth[i];
                 }
                else
                 {
                 	for(int i=h.month;i<12;i++)
                 	  d3=d3+ amonth[i];
                 	for(int i=0;i<month;i++)
                 	  d3=d3+ amonth[i];
				 }

                d4 =abs (day - h.day);
                d = d1 + d2 + d3 + d4;
            } 
            else
            {
                n=(h.year-year)/4;
                d1=n * 366;
                d2=(h.year-year-n)*365;
                if(h.month>month)
                  {	
				    for(int i=month;i<h.month;i++)
                     d3=d3+amonth[i];					 
			    	d4=abs(h.day-day);
                  }
                else if(h.month==month)
                  {
                  	if(day>h.day)d4=h.day-day;
                  	else d4=day-h.day;
				  }
                else
                 {
                 	for(int i=month;i<12;i++)
                 	   d3=d3+ amonth[i];
                 	for(int i=0;i<h.month;i++)
                 	    d3=d3+ amonth[i];
					d4=abs(h.day-day);
				 }  
                
                d=d1 + d2 + d3 + d4;
            }
        }
    }
    return d;
}

int main()
{

    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime t2(2000, 1, 1); //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())     //如果日期和时间合法，则计算天数
    {
        int days = 0;
        days = t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days = t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}
