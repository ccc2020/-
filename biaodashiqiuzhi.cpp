#include<iostream>
#include<cstring>
#include<stack>
#include<cctype> //判断参数类型 
#include<cstdio>
using namespace std;
stack<char>opter;//运算符栈
stack<double>opval;//操作数栈
int getIndex(char sign)
{
    int index=0;
	switch(sign)
	{
		case '+':index=0;break;
		case '-':index=1;break;
		case '*':index=2;break;
		case '/':index=3;break;
		case '(':index=4;break;
		case ')':index=5;break;
		case '#':index=6;
		default:break;	
	}	
	return index;
} 
char getPriority(char sign1,char sign2) //获取优先级
{
	const char priority[][7]=
	{ 
	    {'>','>','<','<','<','>','>'},
	    {'>','>','<','<','<','>','>'},
	    {'>','>','>','>','<','>','>'},
	    {'>','>','>','>','<','>','>'},
	    {'<','<','<','<','<','=','0'},
	    {'>','>','>','>','0','>','>'},
	    {'<','<','<','<','<','0','='},
	};
	int index1=getIndex(sign1);
	int index2=getIndex(sign2);
	return priority[index1][index2];
}
double calculate(double b,char sign,double a)//计算b sign a的值 
{
	switch(sign)
	{
		case '+':return b+a;
		case '-':return b-a;
		case '*':return b*a;
		case '/':return b/a;
		default:break;
	}
} 
double getAnswer()
{
	opter.push('#');
	int count=0;//count表示有多少个数字入栈参与运算
	char c=getchar();
	while(c!='#'||opter.top()!='#')
	{
		if(isdigit(c))   //判断c是否在'0'~'9'之间
		{
			if(count==1)     //count=1表示上一字符也是数字，将其合并
			{
				double t=opval.top();
				opval.pop();
				opval.push(t*10+(c-'0'));
				count=1;
			} 
			else
			{
				opval.push(c-'0');
				count++;
			}
		c=getchar();
		} 
		else
		{
			count=0;
			switch(getPriority(opter.top(),c)) //获取运算符栈opter栈顶元素与c之间的优先级 
			{
				case'<':opter.push(c);c=getchar();break;//将c入栈opter
				case'=':opter.pop();c=getchar();break;//将opter栈顶元素弹出，用于括号处理
				case'>':             //进行计算 
				char sign=opter.top();
				opter.pop();
				double a=opval.top(); 
                opval.pop();
				double b=opval.top();
				opval.pop();
				opval.push(calculate(b,sign,a));			
			}
		}
	} 
	return opval.top();
} 
int main()
{
	getchar();
	while(getchar()!='\r')
	{
	  while(!opter.empty())opter.pop();
	  while(!opval.empty())opval.pop();
	  double answer=getAnswer();
	  cout<<answer<<endl;
	  getchar();
    }
	return 0; 
}
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   




