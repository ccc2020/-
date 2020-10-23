#include<iostream>
using namespace std;
template<typename T>
class LKList{
struct LNode{
	T data;
	LNode*next;
};
LNode*head;
public:
	LKList();
	virtual ~LKList();
	bool get(int i,T&e);
	bool insert(int i,T e);
	bool remove(int i);
	bool insert_front(T e);
	bool push_back(T e);
	bool remove_front();
	bool pop_back();
	int size();
	int find(T e);
	void print();
};
template<typename T>
LKList<T>::LKList()
{
	head=new LNode();
	if(!head) throw"No Memory";
	head->next=NULL;
}
template<typename T>
LKList<T>::~LKList()
{
	LNode *p;
	while(head->next!=0)
	{
		p=head->next;
		delete head;
		head=p;
	}
	delete head;
}
template<typename T>
bool LKList<T>::get(int i,T&e)
{
	LNode*p=head->next;
	int j=1;
	while(p&&j<i)    //ѭ��ֱ��pΪ�ջ��˵�i���ڵ� 
	{
		p=p->next;
		++j;
	}
	if(!p||j>i) return false;//��i���ڵ㲻���� 
	e=p->data;     //copy���ݵ�e�� 
	return true;
}
template<typename T>
bool LKList<T>::insert(int i,T e)
{
    LNode*p=head;
	int j=0;
	while(p&&j<i-1)   
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1) return false;//��i���ڵ㲻���� 	
    LNode *s=new LNode();    //����һ���µĽڵ㡣�����ӵ�L�� 
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
template<typename T>
bool LKList<T>::remove(int i)
{
	LNode*p=head;
	int j=0;
	while(p&&j<i-1)    //ѭ��ֱ��pΪ�ջ��˵�i���ڵ� 
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1) return false;//��i���ڵ㲻���� 
	LNode*q=p->next;//qָ���ɾ���ڵ�
	p->next=q->next;//ʹq��������
	delete q;    //�ͷ�q�Ŀռ�
	return true;	
} 
template<typename T>
bool LKList<T>::insert_front(T e)
{
	LNode *q=new LNode();
	if(!q) return false;
	q->data=e;
	q->next=0;
	q->next=head->next;//�½ڵ��ͷ����nextָͬ�� 
	head->next=q;  //�½ڵ����ͷ�����档��Ϊ�׽ڵ� 
	return true;
}
template<typename T>
bool LKList<T>::remove_front()
{
    LNode*p=head->next;
    LNode*q=p->next;
    if(p!=0)
	{
		head->next=q;
		delete p;
	}
} 
template<typename T>
bool LKList<T>::push_back(T e)
{
	LNode*p=new LNode;
	LNode*tail;
	p->data=e;
	if(head==NULL)
	{
	p=head->next;
	p->next=NULL;
    }
	else
	{
		tail=head;
		while(tail->next!=NULL)
		   tail=tail->next;
		tail->next=p;
		p->next=NULL;
	}
		
	
	return true;
}
template<typename T>
bool LKList<T>::pop_back()
{
	LNode*p=head;
	LNode*q=head;
	if(!p||!q)return false;
	while(p)
	{
		q=p->next;
		if(q!=0&&q->next==0)
		{
		  delete q;
		  p->next=0;
		  return true;
     	}
     	p=p->next;
	}
}
template<typename T>
int LKList<T>::size()
{
	int count=0;
	LNode*p=head;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
template<typename T>
int LKList<T>::find(T e)
{
	LNode*p=head;
	int i=0;
	while(p)
	{
		if(p->data==e)
		   return i;
		p=p->next;
		i++;
	}
}
template<typename T>
void LKList<T>::print()
{

	LNode*p=head->next;
	while(p!=NULL)
	{
		cout<<p->data<<'\t';
		p=p->next;
	}
}
int main()
{
	int i=0;
	LKList<int>L;
	i=L.size();
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);
	L.print();
	L.insert_front(1);
	L.print();
	L.insert(1,2);
	L.print();
	L.remove(4);
	L.print();
	L.remove_front();
	L.print();
	L.pop_back();
	L.print();
}
