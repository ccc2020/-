#include<iostream>
using namespace std;
#define max_size 100
typedef struct ArcNode{
	int adjvex;       //该边所指向的顶点的位置 
	struct ArcNode *nextarc;//指向下一条边的指针 
	int *info;//该边相关信息的指针 
}ArcNode;   //边表 
typedef struct VNode{
	char data;//顶点信息 
	ArcNode*firstarc;//指向第一条依附该顶点的边的指针 
}VNode;
typedef struct{
	VNode Adjlist[max_size];//邻接表 
	int vexnum,arcnum;//图的当前顶点数和边数 
}AGraph;
void CreateGraph(AGraph *G)
{
	cout<<"请输入顶点数和边数"<<endl;
	cin>>G->vexnum>>G->arcnum;
	cout<<"请输入顶点相关信息"<<endl;
	for(int i=0;i<G->vexnum;i++)
	{
		getchar();
		cin>>G->Adjlist[i].data;
		G->Adjlist[i].firstarc=NULL;//指向边表的指针初始时置零 
	} 
	ArcNode*p;//建立边表
	cout<<"请输入边的顶点序号"<<endl;
	for(int k=0;k<G->arcnum;k++)
	{
		int i,j;
		cin>>i>>j;
		p=new ArcNode;
		p->adjvex=j;//存储边头 
		p->nextarc=G->Adjlist[i].firstarc;
		G->Adjlist[i].firstarc=p;     //头插法插入边结点 
	} 
	cout<<"邻接表："<<endl;
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
