#include<iostream>
using namespace std;
 static int buyCoke(int drink, int bottles, int caps);
 
int main()
{
	int d,b,c,k=0;
	cin>>d;
	b=c=d;
    k=buyCoke(d,b,c);
    cout<<k;
    return 0;
	
} 
 static int buyCoke(int drink, int bottles, int caps)
 {
int sum = drink;//定义sum变量，用来记录每一轮兑换的瓶数，初始化赋值drink
if (bottles < 2 && caps< 3) {
return sum;
}
sum = bottles / 2 + caps / 3;
bottles = bottles % 2 + sum;
caps = caps % 3 + sum;
return buyCoke(sum, bottles, caps) + drink;//这里要加上最初的20瓶
}
