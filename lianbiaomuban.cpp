#include <iostream>
#include <iomanip>
#include <malloc.h>
using namespace std;
template<typename T> 
struct node
{
    T data;
   struct node* next;
};
template<typename T>
class linkedList
{
public:
    linkedList();//构造函数
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert( T value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( T pos, T& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    node<T>* head;
    int len;
};
//请在此处补充所有成员函数的实现
template<typename T>linkedList<T>::linkedList()
{
	head=this->head;
	len=0;
}
template<typename T>
linkedList<T>::~linkedList()
{
	if(head==NULL)delete head;
	else
	{ 
	while(head->next != NULL)
    {
       node<T>*temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
	}
}
template<typename T> 
bool linkedList<T>::initiate()
{
   if(NULL==(head=new node<T>))return false;
   head->next=NULL;
   return true;
}
template<typename T> 
bool linkedList<T>::remove( T pos, T& value)
{  
  int count=1;
   if(pos==0){cout<<"pos <= 0, failed"<<endl;return false;}
   if(pos>Length()){cout<<"pos > len, failed"<<endl;return false;}
   if(head==NULL||head->next==NULL){return false;}
   node<T> *p=head->next;  
   node<T> *q=head;
       while(p!=NULL){ 
		 if(count==pos){
		   q->next=p->next;
		   value=p->data;
		   free(p);
		   len--;
		   return true;
	   } 
		 else{
		   q=p;
		   p=p->next;
	   } count++;
 }
   return false;
}
template<typename T> 
bool linkedList<T>::isEmpty()
{
  if(head==NULL)return true;
  else return false;
}
template<typename T> 
void linkedList<T>::insert( T value )
{  
  
   static node<T> *rear=head;
   node<T> *p=new node<T>;
   p->data=value;
   p->next=NULL;
   rear->next=p;
   rear=p;
   len++;
}
template<typename T> 
int linkedList<T>::Length()
{
  
  if(head==NULL)return -1;
  else return len;
}


//成员函数print
template<typename T> 
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}

