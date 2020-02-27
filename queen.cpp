#include<iostream> 
using namespace std;
int main()
{
    int a[8][8];        //代表棋盘，从1开始。
	char ch[8];  
	     //输入的数据。
   
	int i,j,k,row,col;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			a[i][j]=0;   //初始化，假设0可以放置皇后。 
	cin>>ch;
	for(i=0;i<8;i++)
	{
		if(ch[i]!='*')
		{
			k=ch[i]-'1';//k为皇后放置的列数。 
			for(j=0;j<8;j++)
			{
				a[i][j]=1;
				a[j][k]=1;//将皇后的列和行都置为1，不能再放置其他皇后。 
			}
            row=i-1;
			col=k-1;
			while(row>=0&&row<=7&&col>=0&&col<=7)
			{
				a[row--][col--]=1;
			}//左斜线置为1. 
			row=i+1;
			col=k+1;
			while(row>=0&&row<=7&&col>=0&&col<=7)
			{
				a[row++][col++]=1;
			} //右斜线置为1。 
        }
    }
    k=0;
    for(i=0;i<8;i++)
   {
	    for(j=0;j<8;j++)
        {
		if(a[i][j]==0) 
		k=j+1;
		
	 
	}} //寻找0位置，即可以放置第八个皇后的位置。 
	if(k!=0)cout<<k;
	else cout<<"No Answer";
	return 0;
      
}































