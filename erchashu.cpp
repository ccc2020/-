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
	   void createTree(BTNode*&node,const char*&str);  //创建二叉树 
	   void preorder(BTNode*p);   //前序遍历（递归） 
	   void inorder(BTNode*p);	  //中序遍历（递归） 
	   void postorder(BTNode*p);  //后序遍历（递归） 
	   BTNode *search(BTNode*p,char k); //查找值为k的结点 
	   int height(BTNode*p);            //求树的高度 
	   BTNode *parent(BTNode*p,char k); //找父结点 
	   BTNode *leftchild(BTNode*p);     //找左孩子 
	   BTNode *rightchild(BTNode*p);    //找右孩子
	   void preorder1(BTNode*p);   //前序遍历（非递归 栈） 
	   void inorder1(BTNode*p);	  //中序遍历（非递归 栈） 
	   void postorder1(BTNode*p);  //后序遍历（非递归 栈） 
	   void copy(BTNode*p,BTNode *&n);//复制 
		   
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
	cout<<"先序递归遍历"<<endl; 
	t.preorder(t.BTroot);
	cout<<endl;
	t.copy(t.BTroot,a);
	cout<<"后序非递归遍历"<<endl;
	t.postorder(a);
	cout<<endl;
	cout<<"中序递归遍历"<<endl; 
	t.inorder(t.BTroot);
	cout<<endl;
	cout<<"查找值为k的结点的左孩子和右孩子"<<endl;
	b=t.search(t.BTroot,'A'); 
	cout<<b->lchild->data;
	cout<<b->rchild->data;
	cout<<endl;
	cout<<"树的高度"<<endl;
	cout<<t.height(t.BTroot)<<endl;
}            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            


