#include<iostream>
#include<stack>
using namespace std;
class BTNode
{
	public:
	   char data;
	   BTNode*lchild;
	   BTNode*rchild;
	   BTNode(){lchild=NULL;rchild==NULL;}
	   BTNode(char ch){data=ch;lchild=NULL;rchild==NULL;}
};
class Tree
{
	public:
	   BTNode*BTroot;
	   Tree(){BTroot=NULL;}
	   void createTree(BTNode*&node,const char*&str);  //���������� 
	   void preorder(BTNode*p);   //ǰ��������ݹ飩 
	   void inorder(BTNode*p);	  //����������ݹ飩 
	   void postorder(BTNode*p);  //����������ݹ飩 
	   BTNode *search(BTNode*p,char k); //����ֵΪk�Ľ�� 
	   int height(BTNode*p);            //�����ĸ߶� 
	   BTNode *parent(BTNode*p,char k); //�Ҹ���� 
	   BTNode *leftchild(BTNode*p);     //������ 
	   BTNode *rightchild(BTNode*p);    //���Һ���
	   void preorder1(BTNode*p);   //ǰ��������ǵݹ� ջ�� 
	   void inorder1(BTNode*p);	  //����������ǵݹ� ջ�� 
	   void postorder1(BTNode*p);  //����������ǵݹ� ջ�� 
	   void copy(BTNode*p,BTNode *&n);//���� 
		   
};
void Tree::createTree(BTNode*&node,const char*&str)
{
	if(*str=='#'||*str=='\0')  node=NULL;
	else
	{
		node=new BTNode(*str);
		createTree(node->lchild,++str);
		createTree(node->rchild,++str);
	}
}
void Tree::preorder(BTNode*p)
{
	if(p!=NULL)
	{
		cout<<p->data;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void Tree::inorder(BTNode*p)
{
	if(p!=NULL)
	{   inorder(p->lchild);
		cout<<p->data;
		inorder(p->rchild);
	}
}
void Tree::postorder(BTNode*p)
{
	if(p!=NULL)
	{   postorder(p->lchild);
    	postorder(p->rchild);
		cout<<p->data;
	}
}            
int Tree::height(BTNode*p)           
{
	int L=0,R=0;
	if(p==NULL) return 0;
	else
	{
		L=height(p->lchild);
		R=height(p->rchild);
		return (L>R?L:R)+1;
	}
}            
BTNode *Tree::search(BTNode*p,char k)            
{
    BTNode*q=NULL;
    if(p!=NULL)
    {
    	if(p->data==k) q=p;
    	else
    	{
    		q=search(p->lchild,k);
    		if(q==NULL)
    		q=search(p->rchild,k);
		}
	}
    return q;
}            
BTNode *Tree::parent(BTNode*p,char k)            
{
	BTNode*q=NULL;
	if(p==NULL||p->data==k)	return NULL;
    if(p->lchild!=NULL&&p->lchild->data==k||p->rchild!=NULL&&p->rchild->data==k) return p;
    else
    {
    	q=parent(p->lchild,k);
    	if(q==NULL) q=parent(p->rchild,k);
    	return q;
	}
}            
BTNode *Tree::leftchild(BTNode*p)            
{
	if(p!=NULL) return p->lchild;
	return NULL;
}            
BTNode *Tree::rightchild(BTNode*p)            
{
	if(p!=NULL) return p->rchild;
	return NULL;
}              
void Tree::preorder1(BTNode*p)            
{
	stack<BTNode*>s;
	s.push(p);
	while(!s.empty())
	{
		BTNode*q=s.top();
		cout<<q->data<<" ";
		s.pop();
		if(q->rchild!=NULL) s.push(p->rchild);
		if(q->lchild!=NULL) s.push(p->lchild);
	}
}            
void Tree::inorder1(BTNode*p)     
{
	stack<BTNode*>s;
	BTNode*q=p;
	while(q||!s.empty())
	{
		if(q!=NULL)
		{
			s.push(q);
			q=q->lchild;
		}
		else
		{
			q=s.top();
			cout<<q->data;
			s.pop();
			q=q->rchild;
		}
	}
}       
void Tree::postorder1(BTNode*p)            
{
	stack<BTNode*>s;
	BTNode*pre=NULL;
	s.push(p);
	while(!s.empty())
	{
		BTNode*cur=s.top();
		if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
		{
			cout<<cur->data;
			s.pop();
			pre=cur;
		}
		else
		{
			if(cur->rchild!=NULL) s.push(cur->rchild);
			if(cur->lchild!=NULL) s.push(cur->lchild);
		}
	}
}            
void Tree::copy(BTNode*p,BTNode *&n)            
{
	if(p==NULL) n=NULL;
	else
	{
		n=new BTNode;
		n->data=p->data;
		copy(p->lchild,n->lchild);
		copy(p->rchild,n->rchild);
	}
}         
int main()
{
	const char *str="ABC##D##E##";
	BTNode *a;
	BTNode *b;
	Tree t;
	t.createTree(t.BTroot,str);
	cout<<"����ݹ����"<<endl; 
	t.preorder(t.BTroot);
	cout<<endl;
	t.copy(t.BTroot,a);
	cout<<"����ǵݹ����"<<endl;
	t.postorder(a);
	cout<<endl;
	cout<<"����ݹ����"<<endl; 
	t.inorder(t.BTroot);
	cout<<endl;
	cout<<"����ֵΪk�Ľ������Ӻ��Һ���"<<endl;
	b=t.search(t.BTroot,'A'); 
	cout<<b->lchild->data;
	cout<<b->rchild->data;
	cout<<endl;
	cout<<"���ĸ߶�"<<endl;
	cout<<t.height(t.BTroot)<<endl;
}            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            


