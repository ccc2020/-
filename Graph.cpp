#include<iostream>
using namespace std;
#define max_size 100
typedef struct ArcNode{
	int adjvex;       //�ñ���ָ��Ķ����λ�� 
	struct ArcNode *nextarc;//ָ����һ���ߵ�ָ�� 
	int *info;//�ñ������Ϣ��ָ�� 
}ArcNode;   //�߱� 
typedef struct VNode{
	char data;//������Ϣ 
	ArcNode*firstarc;//ָ���һ�������ö���ıߵ�ָ�� 
}VNode;
typedef struct{
	VNode Adjlist[max_size];//�ڽӱ� 
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͱ��� 
}AGraph;
void CreateGraph(AGraph *G)
{
	cout<<"�����붥�����ͱ���"<<endl;
	cin>>G->vexnum>>G->arcnum;
	cout<<"�����붥�������Ϣ"<<endl;
	for(int i=0;i<G->vexnum;i++)
	{
		getchar();
		cin>>G->Adjlist[i].data;
		G->Adjlist[i].firstarc=NULL;//ָ��߱��ָ���ʼʱ���� 
	} 
	ArcNode*p;//�����߱�
	cout<<"������ߵĶ������"<<endl;
	for(int k=0;k<G->arcnum;k++)
	{
		int i,j;
		cin>>i>>j;
		p=new ArcNode;
		p->adjvex=j;//�洢��ͷ 
		p->nextarc=G->Adjlist[i].firstarc;
		G->Adjlist[i].firstarc=p;     //ͷ�巨����߽�� 
	} 
	cout<<"�ڽӱ�"<<endl;
	for(int i=0;i<G->vexnum;i++)
	{
		p=G->Adjlist[i].firstarc;
		cout<<G->Adjlist[i].data<<":";
		while(p)
		{
			cout<<G->Adjlist[p->adjvex].data;
			p=p->nextarc;
		}
		cout<<endl;
	} 
	cout<<endl;
}
void Visit(int v)
{
	cout<<v<<" ";
}
int visit[max_size];
void DFS(AGraph*G,int v)
{
	ArcNode *p;
	visit[v]=1;
	Visit(v);
	p=G->Adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visit[p->adjvex]==0)
		DFS(G,p->adjvex);
		p=p->nextarc;
	}
}
void BFS(AGraph*G,int v,int visit[max_size])
{
	ArcNode *p;
	int que[max_size],front=0,rear=0;
	int j;
	Visit(v);
	visit[v]=1;
	rear=(rear+1)%max_size;
	que[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%max_size;
		j=que[front];
		p=G->Adjlist[j].firstarc;
		while(p!=NULL)
		{
			if(visit[p->adjvex]==0)
			{
				Visit(p->adjvex);
				visit[p->adjvex]=1;
				rear=(rear+1)%max_size;
				que[rear]=p->adjvex;
			}
			p=p->nextarc;
		}
	}
}
int main()
{
	AGraph G;
	CreateGraph(&G);
	cout<<"DFS:"<<endl;
	DFS(&G,0);
	cout<<endl;
	cout<<"BFS:"<<endl;
	int v[max_size]={0}; 
	BFS(&G,0,v);
	cout<<endl; 
}
