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
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( T value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( T pos, T& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    node<T>* head;
    int len;
};
//���ڴ˴��������г�Ա������ʵ��
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


//��Ա����print
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
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}

