#include<iostream>
using namespace std;
//冒号排序
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
//快速排序 
void QuickSort(int R[],int low,int high)//对从R[low]到R[high]的关键字进行排序 
{
	int temp;
	int i=low,j=high;
	if(low<high) 
	{
		temp=R[low];
		while(i<j)
		{
			while(j>i&&R[j]>=temp)  --j;//从右往左扫描，找到一个小于temp的关键字
			if(i<j)
			{
				R[i]=R[j];   //放在temp左边 
				++i;		 //i右移一位		
			} 
			while(i<j&&R[i]<temp)   ++i;//从左往右扫描，找到一个大于temp的关键字
			if(i<j)
			{
				R[j]=R[i];  //放在temp右边 
				--j;		//j左移一位		
			} 
		}
		R[i]=temp;   //将temp放在最终位置 
		QuickSort(R,low,i-1);   //递归地对temp左边的关键字进行排序 
		QuickSort(R,i+1,high);  //递归地对temp右边的关键字进行排序 
	}
}
 //本函数在数组R[low]到R[high]的范围内对在位置low上的结点进行调整
void Sift(int R[],int low,int high)//这里关键字的存储设定为从数组下标1开始
{
    int i=low,j=2*i;
	int temp=R[i];
	while(j<=high)
	{
		if(j<high&&R[j]<R[j+1])  //若右孩子较大，则把j指向右孩子 
		    ++j;    //j变为2*i+1 
		if(temp<R[j])
		{
			R[i]=R[j];  //将R[j]调整到双亲结点的位置上 
			i=j;        //修改i和j的值，以便继续向下调整 
			j=2*i;
		} 
		else break;
	} 
	R[i]=temp;	
} 
//堆排序
void heapSort(int R[],int n)
{
	int i;
	int temp;
	for(i=n/2;i>=1;--i)
	   Sift(R,i,n);
	for(i=n;i>=2;--i)  //进行n-1次循环，完成堆排序 
	{
		/*以下3句换出了根结点中的关键字，将其放入最终位置*/
		temp=R[1];
		R[1]=R[i];
		R[i]=temp;
		Sift(R,1,i-1);   //在减少了1个关键字的无序序列中进行调整 
	}
} 
//直接插入排序 
void InsertSort(int R[],int n)
{
	int i,j;
	int temp;
	for(i=1;i<n;++i)
	{
		temp=R[i];  //将待插入关键字暂存于ftemp中 
		j=i-1;
		/*while循环完成了从待排关键字之前的关键字开始扫描，如果大于待排关键字，则后移一位*/
		while(j>=0&&temp<R[j])
		{
			R[j+1]=R[j];
			--j;
		} 
		R[j+1]=temp;   //找到插入位置，将temp中暂存的待排关键字插入 
	}
}
int main()
{
	int a[8]={49,38,65,97,76,13,27,49};
	int b[8]={49,38,65,97,76,13,27,49};
	int c[9]={0,49,38,65,97,76,13,27,49};
	int d[8]={49,38,65,97,76,13,27,49};
	cout<<"原序列："<<endl;
	cout<<"49 38 65 97 76 13 27 49"<<endl;
	cout<<"冒泡排序："<<endl; 
	BubbleSort(a,8);
	for(int i=0;i<8;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	cout<<"快速排序："<<endl; 
	QuickSort(b,0,7);
	for(int i=0;i<8;i++)
	 cout<<b[i]<<" ";
	cout<<endl;
	cout<<"堆排序："<<endl;
	heapSort(c,8);
	for(int i=1;i<9;i++)
	 cout<<c[i]<<" ";
	cout<<endl;
	cout<<"直接插入排序："<<endl;
	InsertSort(d,8);
	for(int i=0;i<8;i++)
	 cout<<d[i]<<" ";
} 










