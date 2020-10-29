#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class SqStack{
    T*data,*top_;
    int capacity;
	public:
		SqStack(int cap);
		bool push(T e);
		bool pop();
		T top();
		bool empty();
		void clear();
		void print();
};
template<typename T>
SqStack<T>::SqStack(int cap)
{
	cap=5;
	//分配空间
	data=new T[cap];
	if(!data)  throw"No Memory";
	capacity=cap;   //设置大小 
	top_=data;   //设置指针 
}
template<typename T>
bool SqStack<T>::push(T e)
{
	//若空间不够重新匹配
	if(top_-data>=capacity)
	{
		T*p=new T[2*capacity];
		if(!p)return false;
		for(int i=0;i<capacity;i++)
		    p[i]=data[i];
		delete[]data;
		data=p;
		top_=data+capacity;
		capacity=2*capacity;
	} 
	*top_=e;
	top_++;    //插入数据 
}
template<typename T>
bool SqStack<T>::pop()
{
	if(top_==data)  return false;
	top_--;
	return true;
}
template<typename T>
T SqStack<T>::top()
{
	if(top_==data)  throw"Empty,Error!";
	return *(top_-1);
}
template<typename T>
bool SqStack<T>::empty()
{
	if(top_==data) return true;
	else return false;
}
template<typename T>
void SqStack<T>::clear()
{
	while(!empty()){pop();} 
}
template<typename T>
void SqStack<T>::print()
{
	while(data<top_){cout<<*data;data++;} 
}
int main()
{
	SqStack<int>Stack(0);
	Stack.push(1);
	Stack.push(2);
	Stack.push(3);
	Stack.push(4);
	Stack.print();
	Stack.push(5);
	Stack.push(6);
	Stack.push(7);
	Stack.pop();
	Stack.print();
	
}






























