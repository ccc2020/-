#include<iostream> 
using namespace std;
int main()
{
    int a[8][8];        //�������̣���1��ʼ��
	char ch[8];  
	     //��������ݡ�
   
	int i,j,k,row,col;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			a[i][j]=0;   //��ʼ��������0���Է��ûʺ� 
	cin>>ch;
	for(i=0;i<8;i++)
	{
		if(ch[i]!='*')
		{
			k=ch[i]-'1';//kΪ�ʺ���õ������� 
			for(j=0;j<8;j++)
			{
				a[i][j]=1;
				a[j][k]=1;//���ʺ���к��ж���Ϊ1�������ٷ��������ʺ� 
			}
            row=i-1;
			col=k-1;
			while(row>=0&&row<=7&&col>=0&&col<=7)
			{
				a[row--][col--]=1;
			}//��б����Ϊ1. 
			row=i+1;
			col=k+1;
			while(row>=0&&row<=7&&col>=0&&col<=7)
			{
				a[row++][col++]=1;
			} //��б����Ϊ1�� 
        }
    }
    k=0;
    for(i=0;i<8;i++)
   {
	    for(j=0;j<8;j++)
        {
		if(a[i][j]==0) 
		k=j+1;
		
	 
	}} //Ѱ��0λ�ã������Է��õڰ˸��ʺ��λ�á� 
	if(k!=0)cout<<k;
	else cout<<"No Answer";
	return 0;
      
}































