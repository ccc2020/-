#include<iostream>
#include<iomanip>
using namespace std;
class Huffman
{
	public:
	    int weight;
		int parents;
		int lchild;
		int rchild;
		Huffman(){this->parents=-1;this->lchild=-1;this->rchild=-1;}
		
};
class HuffmanCode
{
	public:
		char ch;
		char *hfcode;
};
void Select_2min(Huffman*hf,int n,int &m1,int &m2)//����HF����ѡ��Ȩ��С������ 
{
	for(int i=0;i<n;i++)
	{
		if(hf[i].parents==-1)
		{
			m1=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(hf[i].parents==-1&&hf[i].weight<hf[m1].weight)  m1=i;
	}
	for(int i=0;i<n;i++)
	{
		if(hf[i].parents==-1&&i!=m1)
		{
			m2=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(hf[i].parents==-1&&hf[i].weight<hf[m2].weight&&i!=m1) m2=i;
	}
}
void createHFTree(Huffman*hf,int n,int a[])  //����HF�� 
{
	for(int i=0;i<=2*n-1;i++)
	{
		hf[i].weight=a[i];//����ֻ�и�����hf�� 
	}
	for(int i=n;i<2*n-1;i++)
	{
		int m1=0,m2=0;
		Select_2min(hf,i,m1,m2);
		hf[i].weight=hf[m1].weight+hf[m2].weight;
		//���Һ�����Ȩֵ��С�ķ�����ߣ�Ȩֵ�ϴ�ķ����ұ�
		if(m1<=m2)
		{
			hf[i].lchild=m1;
			hf[i].rchild=m2;
		}
		else
		{
			hf[i].lchild=m2;
			hf[i].rchild=m1;
		}
		hf[m1].parents=i;
		hf[m2].parents=i; 
	}
}
void printHFTree(Huffman*hf,int n)  //��ӡHF�� 
{
    cout<<"index weight parents lchild rchild"<<endl;
	cout<<left;
	for(int i=0;i<2*n-1;i++)
	{
		cout<<setw(6)<<i<<" ";
		cout<<setw(6)<<hf[i].weight<<" ";
		cout<<setw(6)<<hf[i].parents<<" ";
		cout<<setw(6)<<hf[i].lchild<<" ";
		cout<<setw(6)<<hf[i].rchild<<" "<<endl;
	}
}
void createHFCode(Huffman*hf,HuffmanCode*hf_code,int n,char*ch)//����HF���� 
{
	for(int i=0;i<n;i++)
	{
		hf_code[i].ch=ch[i];//�����ַ� 
	}
	char*tempcode=new char[n];//��ʱ��ű���
	for(int i=0;i<n;i++)
	{
		int front=hf[i].parents;//��ʾ��ǰ���˫��λ�� 
		int temp=i;//��¼��ǰ��� 
		int index=n-1;
		tempcode[n-1]='\0';
		while(front!=-1)//�ҵ������
		{
			--index;
			if(hf[front].lchild==temp) {tempcode[index]='0';}
			else {tempcode[index]='1';}
			temp=hf[temp].parents;
			front=hf[front].parents;
		}
		hf_code[i].hfcode=new char[n-index];
		for(int j=0;j<n-index;j++)
		    hf_code[i].hfcode[j]=tempcode[j+index];
	} 	
}
void printHFCode(HuffmanCode*hf_code,int n)  //��ӡHF���� 
{
	for(int i=0;i<n;i++)
	{
		int j=0;
		cout<<hf_code[i].ch<<" Huffmancode is:";
		while(hf_code[i].hfcode[j]!='\0')
		{
			cout<<hf_code[i].hfcode[j]<<" ";
			j++;
		}
		cout<<endl;
		j=0;
	}
}
int main()
{
	int n;
	cout<<"Ҷ�Ӹ���"<<endl;
	cin>>n;
	int a[8]={1,1,2,3,6,3,2,1};
	char ch[8]={'A','B','C','D','E','F','G','H'};
	Huffman*hf=new Huffman[2*n-1];
	createHFTree(hf,n,a);
	printHFTree(hf,n);
	HuffmanCode*hf_code=new HuffmanCode[n];
	createHFCode(hf,hf_code,n,ch);
	printHFCode(hf_code,n);
	system("pause");
	return 0;
}






