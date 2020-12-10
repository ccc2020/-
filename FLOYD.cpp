#include<iostream>
#define MAX_VERTEX_NUM 20   //��󶥵���� 
#define INFINITY INT_MAX   //���ֵ ���� 
using namespace std;
typedef struct{
	char vexs[MAX_VERTEX_NUM]; //�������� 
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //�ڽӾ��� 
	int vexnum,arcnum;  //ͼ�ĵ�ǰ�������ͱ��� 
}MGraph;
int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
void CreateMGraph(MGraph &G)
{
	int i,j,k,w=0;
	cout<<"�����붥�����ͱ���"<<endl;
	cin>>G.vexnum>>G.arcnum;
	cout<<"����������Ϣ"<<endl;
	for( i=0;i<G.vexnum;i++)
	  cin>>&(G.vexs[i]);
	for( i=0;i<G.vexnum;i++)
	{
		for(int j=0;j<G.vexnum;j++)
		  G.arcs[i][j]=INFINITY;
	}
	for( k=0;k<G.arcnum;k++)
	{
		cout<<"������(vi,vj)�е��±�i��j��Ȩֵw��"<<endl;
		cin>>i>>j>>w;
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j];
	}
}
void print(MGraph *g)
{
	cout<<"�ڽӾ���"<<endl;
	for(int i=0;i<g->vexnum;i++)
	{
		for(int j=0;j<g->vexnum;j++)
		cout<<g->arcs[i][j]<<" ";
		cout<<endl;
	}
}
void FLOYD(MGraph G)
{
	
	for(int v=0;v<G.vexnum;++v)
	   for(int w=0;w<G.vexnum;++w)
	   {
	       D[v][w]=G.arcs[v][w];
	       p[v][w]=w;
		   
       }
    for(int u=0;u<G.vexnum;++u)
	   for(int v=0;v<G.vexnum;++v)
	      for(int w=0;w<G.vexnum;++w)
	         if(D[v][u]+D[u][w]<D[v][w])
	         {
	         	D[v][w]=D[v][u]+D[u][w];
	         	p[v][w]=p[v][u];
			 }	
}
void printFLOYD(MGraph G)
{
	int i,j,k;
    cout<<"������֮������·�����£�"<<endl;
	for(i=0;i<G.vexnum;++i)
	{
		for(j=i+1;j<G.vexnum;++j)
		 {
		 	cout<<"v"<<i<<"--"<<"v"<<j<<" "<<"weight"<<D[i][j]<<"path:"<<i<<"->";
		    k=p[i][j];
			while(k!=j)
			{
				cout<<k<<"->";
				k=p[k][j];
			 } 
			cout<<j<<endl;
		 }
		 cout<<endl;
	 } 
}
int main()
{
	MGraph mg;
	CreateMGraph(mg);
	print(&mg);
	FLOYD(mg);
	printFLOYD(mg);
} 
