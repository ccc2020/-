#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
void swap(int *p1, int *p2)                         //���������е���Ԫ��
{
    int temp = *p1;                                 //������������Ԫ��p1��ָ��
    *p1 = *p2;                                      //��Ԫ��p1��ָ���ΪԪ��p2��ָ��
    *p2 = temp;                                     //��Ԫ��p2��ָ���Ϊ֮ǰ�洢��Ԫ��p1��ָ��
}
int main()
{
    int n=0;
    ifstream in("a.txt",ios::in); //Դ�ļ���
    ofstream out("b.txt",ios::out); //Ŀ���ļ�д
    double buffer[20];
	for(int i=0;;i++)
	  {
	   if(!in.eof())  {
	   in>>buffer[i];n=i+1;}
	   else break;
	   }
    in.close ();
      //���������Ԫ�صĸ���
    int i;  //�Ƚϵ�����
    int j;  //ÿ�ֱȽϵĴ���
    double buf;  //��������ʱ���ڴ���м�����
    //n = sizeof(buffer) / sizeof(buffer[0]);  /*a[0]��int��, ռ4�ֽ�, �����ܵ��ֽ�������4����Ԫ�صĸ���*/
    for (i=0; i<n-1; i++)  //�Ƚ�n-1��
    {
        for (j=0; j<n-1-i; j++)  //ÿ�ֱȽ�n-1-i��,
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
