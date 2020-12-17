#include<iostream>
using namespace std;
//ð������
void BubbleSort(int R[],int n) 
{
	int i,j,flag;
	int temp;
	for(i=n-1;i>=1;--i)
	{
		flag=0;
		for(j=1;j<=i;++j)
		   if(R[j-1]>R[j])
		   {
		   	    temp=R[j];
		   	    R[j]=R[j-1];
		   	    R[j-1]=temp;
		   	    flag=1;
		   }
		if(flag==0) return;
	}
}
//�������� 
void QuickSort(int R[],int low,int high)//�Դ�R[low]��R[high]�Ĺؼ��ֽ������� 
{
	int temp;
	int i=low,j=high;
	if(low<high) 
	{
		temp=R[low];
		while(i<j)
		{
			while(j>i&&R[j]>=temp)  --j;//��������ɨ�裬�ҵ�һ��С��temp�Ĺؼ���
			if(i<j)
			{
				R[i]=R[j];   //����temp��� 
				++i;		 //i����һλ		
			} 
			while(i<j&&R[i]<temp)   ++i;//��������ɨ�裬�ҵ�һ������temp�Ĺؼ���
			if(i<j)
			{
				R[j]=R[i];  //����temp�ұ� 
				--j;		//j����һλ		
			} 
		}
		R[i]=temp;   //��temp��������λ�� 
		QuickSort(R,low,i-1);   //�ݹ�ض�temp��ߵĹؼ��ֽ������� 
		QuickSort(R,i+1,high);  //�ݹ�ض�temp�ұߵĹؼ��ֽ������� 
	}
}
 //������������R[low]��R[high]�ķ�Χ�ڶ���λ��low�ϵĽ����е���
void Sift(int R[],int low,int high)//����ؼ��ֵĴ洢�趨Ϊ�������±�1��ʼ
{
    int i=low,j=2*i;
	int temp=R[i];
	while(j<=high)
	{
		if(j<high&&R[j]<R[j+1])  //���Һ��ӽϴ����jָ���Һ��� 
		    ++j;    //j��Ϊ2*i+1 
		if(temp<R[j])
		{
			R[i]=R[j];  //��R[j]������˫�׽���λ���� 
			i=j;        //�޸�i��j��ֵ���Ա�������µ��� 
			j=2*i;
		} 
		else break;
	} 
	R[i]=temp;	
} 
//������
void heapSort(int R[],int n)
{
	int i;
	int temp;
	for(i=n/2;i>=1;--i)
	   Sift(R,i,n);
	for(i=n;i>=2;--i)  //����n-1��ѭ������ɶ����� 
	{
		/*����3�任���˸�����еĹؼ��֣������������λ��*/
		temp=R[1];
		R[1]=R[i];
		R[i]=temp;
		Sift(R,1,i-1);   //�ڼ�����1���ؼ��ֵ����������н��е��� 
	}
} 
//ֱ�Ӳ������� 
void InsertSort(int R[],int n)
{
	int i,j;
	int temp;
	for(i=1;i<n;++i)
	{
		temp=R[i];  //��������ؼ����ݴ���ftemp�� 
		j=i-1;
		/*whileѭ������˴Ӵ��Źؼ���֮ǰ�Ĺؼ��ֿ�ʼɨ�裬������ڴ��Źؼ��֣������һλ*/
		while(j>=0&&temp<R[j])
		{
			R[j+1]=R[j];
			--j;
		} 
		R[j+1]=temp;   //�ҵ�����λ�ã���temp���ݴ�Ĵ��Źؼ��ֲ��� 
	}
}
int main()
{
	int a[8]={49,38,65,97,76,13,27,49};
	int b[8]={49,38,65,97,76,13,27,49};
	int c[9]={0,49,38,65,97,76,13,27,49};
	int d[8]={49,38,65,97,76,13,27,49};
	cout<<"ԭ���У�"<<endl;
	cout<<"49 38 65 97 76 13 27 49"<<endl;
	cout<<"ð������"<<endl; 
	BubbleSort(a,8);
	for(int i=0;i<8;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	cout<<"��������"<<endl; 
	QuickSort(b,0,7);
	for(int i=0;i<8;i++)
	 cout<<b[i]<<" ";
	cout<<endl;
	cout<<"������"<<endl;
	heapSort(c,8);
	for(int i=1;i<9;i++)
	 cout<<c[i]<<" ";
	cout<<endl;
	cout<<"ֱ�Ӳ�������"<<endl;
	InsertSort(d,8);
	for(int i=0;i<8;i++)
	 cout<<d[i]<<" ";
} 










