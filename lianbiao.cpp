#include <iostream>
#include <iomanip>
#include <malloc.h>
using namespace std;

typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    LList *head;
    int len;
};

//���ڴ˴��������г�Ա������ʵ��
linkedList::linkedList()
{
	head=this->head;
	len=0;
}
linkedList::~linkedList()
{
	if(head==NULL)delete head;
	else
	{ 
	while(head->next != NULL)
    {
       PList temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
	}
}
bool linkedList::initiate()
{
   if(NULL==(head=new node))return false;
   head->next=NULL;
   return true;
}
bool linkedList::remove( int pos, int& value)
{  
  int count=1;
   if(pos==0){cout<<"pos <= 0, failed"<<endl;return false;}
   if(pos>Length()){cout<<"pos > len, failed"<<endl;return false;}
   if(head==NULL||head->next==NULL){return false;}
   PList p=head->next;  
   PList q=head;
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
bool linkedList::isEmpty()
{
  if(head==NULL)return true;
  else return false;
}
void linkedList::insert( int value )
{  
  
   static PList rear=head;
   PList node=(PList)malloc(sizeof(LList));
   node->data=value;
   node->next=NULL;
   rear->next=node;
   rear=node;
   len++;
}
int linkedList::Length()
{
  
  if(head==NULL)return -1;
  else return len;
}


//��Ա����print
void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    linkedList L1;
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



