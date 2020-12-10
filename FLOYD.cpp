#include<iostream>
#define MAX_VERTEX_NUM 20   //最大顶点个数 
#define INFINITY INT_MAX   //最大值 无穷 
using namespace std;
typedef struct{
	char vexs[MAX_VERTEX_NUM]; //顶点向量 
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //邻接矩阵 
	int vexnum,arcnum;  //图的当前顶点数和边数 
}MGraph;
int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
void CreateMGraph(MGraph &G)
{
	int i,j,k,w=0;
	cout<<"请输入顶点数和边数"<<endl;
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入结点信息"<<endl;
	for( i=0;i<G.vexnum;i++)
	  cin>>&(G.vexs[i]);
	for( i=0;i<G.vexnum;i++)
	{
		for(int j=0;j<G.vexnum;j++)
		  G.arcs[i][j]=INFINITY;
	}
	for( k=0;k<G.arcnum;k++)
	{
		cout<<"请输入(vi,vj)中的下标i，j和权值w："<<endl;
		cin>>i>>j>>w;
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j];
	}
}
void print(MGraph *g)
{
	cout<<"邻接矩阵："<<endl;
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
    cout<<"各顶点之间的最短路径如下："<<endl;
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
