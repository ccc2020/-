#include<iostream>
using namespace std;
template<typename T>
class SqList{
	public:
		SqList(int cap=100){data=new T[cap];capacity=cap;n=0;}
		bool insert(int i,T e);
		bool remove(int i);
		bool push_back(T e);
		bool insert_front(T e);
		bool get(int i,T&e);
		bool set(int i,T e);
		int size(){return n;}
		int find(T e);
	private:
		bool realloc();
		 T*data;
	    int capacity,n;
};
template<typename T>
bool SqList<T>::realloc()
{
	T*p=new T[2*capacity];
	if(!p)  return false;
	for(int i=0;i<capacity;i++)
	   p[i]=data[i];
	   capacity*=2;
	   delete[]data;
	   data=p;
	   return true;
}
template<typename T>
bool SqList<T>::push_back(T e)
{
	if(n>=capacity)
	   if(!realloc()) return false;
	data[n]=e;
	n++;
	return true;
}
template<typename T>
bool SqList<T>::insert(int i,T e)
{
	if(i<1||i>n+1) return false;//i�Ƿ�Ϸ� 
	if(n>=capacity)
	{
		//���������ڴ�� 
		if(!realloc()) return false;
	}
	for(int j=n;j>=i;j--)
	     data[j]=data[j-1];
	data[i-1]=e;
	n++;
}
template<typename T>
bool SqList<T>::remove(int i)
{
	if(i<1||i>n+1) return false;//i�Ƿ�Ϸ� 
	T *p,*q;
	p=&(data[i]);//pָ��ɾ���Ľڵ�
	q=data+n-1;//qָ�����һ���ڵ�
	for(;p<=q;++p)
	    *(p-1)=*p;   //��p+1��q�����нڵ�ǰ��һ����Ԫ 
	--n;   //����1 
	return true;
}
template<typename T>
bool SqList<T>::set(int i,T e)
{
	if(i<1||i>n+1) return false;//i�Ƿ�Ϸ�
	data[i-1]=e;
	return true;
}
template<typename T>
bool SqList<T>::get(int i,T&e)
{
	if(i<1||i>n+1) return false;//i�Ƿ�Ϸ�
	e=data[i-1];
	return true;
}
template<typename T>
int SqList<T>::find(T e)
{
	for(int i=0;i<n;i++)
	   if(data[i]==e)
	       return i+1;
	return 0;
}
int main()
{
	SqList<char>list;
	list.push_back('H');
	list.push_back('e');
	list.push_back('r');
	list.push_back('h');
	char ch;
	int i;
	for(i=1;i<list.size();i++)
	{
	    	list.get(i,ch);
	    	cout<<ch<<endl;
	}
	list.insert(2,'B');
	list.remove(1);
	for(i=1;i<list.size();i++)
	{
		list.get(i,ch);
		cout<<ch<<endl;
	}
	
	return 0;
}





































