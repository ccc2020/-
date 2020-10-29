#include<iostream>
#include<cstring>
#include<stack>
#include<cctype> //�жϲ������� 
#include<cstdio>
using namespace std;
stack<char>opter;//�����ջ
stack<double>opval;//������ջ
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
char getPriority(char sign1,char sign2) //��ȡ���ȼ�
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
double calculate(double b,char sign,double a)//����b sign a��ֵ 
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
	int count=0;//count��ʾ�ж��ٸ�������ջ��������
	char c=getchar();
	while(c!='#'||opter.top()!='#')
	{
		if(isdigit(c))   //�ж�c�Ƿ���'0'~'9'֮��
		{
			if(count==1)     //count=1��ʾ��һ�ַ�Ҳ�����֣�����ϲ�
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
			switch(getPriority(opter.top(),c)) //��ȡ�����ջopterջ��Ԫ����c֮������ȼ� 
			{
				case'<':opter.push(c);c=getchar();break;//��c��ջopter
				case'=':opter.pop();c=getchar();break;//��opterջ��Ԫ�ص������������Ŵ���
				case'>':             //���м��� 
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
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   
                   




