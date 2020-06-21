#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
void swap(int *p1, int *p2)                         //交换数组中的两元素
{
    int temp = *p1;                                 //创建变量储存元素p1的指针
    *p1 = *p2;                                      //将元素p1的指针改为元素p2的指针
    *p2 = temp;                                     //将元素p2的指针改为之前存储的元素p1的指针
}
int main()
{
    int n=0;
    ifstream in("a.txt",ios::in); //源文件读
    ofstream out("b.txt",ios::out); //目标文件写
    double buffer[20];
	for(int i=0;;i++)
	  {
	   if(!in.eof())  {
	   in>>buffer[i];n=i+1;}
	   else break;
	   }
    in.close ();
      //存放数组中元素的个数
    int i;  //比较的轮数
    int j;  //每轮比较的次数
    double buf;  //交换数据时用于存放中间数据
    //n = sizeof(buffer) / sizeof(buffer[0]);  /*a[0]是int型, 占4字节, 所以总的字节数除以4等于元素的个数*/
    for (i=0; i<n-1; i++)  //比较n-1轮
    {
        for (j=0; j<n-1-i; j++)  //每轮比较n-1-i次,
        {
            if (buffer[j] > buffer[j+1])
            {
                buf = buffer[j];
                buffer[j] = buffer[j+1];
                buffer[j+1] = buf;
            }
        }
    }
    for(int i=0;i<n;i++)
      out<<buffer[i]<<' ';
    out.close ();
    return 0;
}
