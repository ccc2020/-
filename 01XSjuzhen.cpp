#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define N 4
#define MAX_SIZE 100 // �����з���Ԫ��������
typedef int ElemType;
/*
�ھ����У�����ֵΪ0��Ԫ����ĿԶԶ���ڷ�0Ԫ�ص���Ŀ�����ҷ�0Ԫ�طֲ�û�й���ʱ����Ƹþ���Ϊϡ�����
��֮�෴������0Ԫ����Ŀռ�����ʱ����Ƹþ���Ϊ���ܾ���
*/
/*��Ԫ�鶨��*/
typedef struct
{
	int r; /*�к�*/
	int c; /*�к�*/
	ElemType d; /*Ԫ��ֵ*/
}TupNode; 
 /*��Ԫ��洢�ṹ˳�����*/
typedef struct
{
	int rows; // ����ֵ
	int cols; // ����ֵ
	int nums; // ����Ԫ�ظ���
	TupNode data[MAX_SIZE];
}TSMatrix; 
/*����ϡ�����A����Ԫ���˳���洢�ṹt*/
static void create_matrix(TSMatrix &t, ElemType A[N][N])
{
	int i, j;

	t.rows = N; /* ������ֵ*/
	t.cols = N; /* ������ֵ*/
	t.nums = 0; /*����Ԫ�ظ�����ʼ��*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (A[i][j] != 0)
			{
				t.data[t.nums].r = i; /*�к�*/
				t.data[t.nums].c = j; /*�к�*/
				t.data[t.nums].d = A[i][j]; /*Ԫ��ֵ*/
				t.nums++; /*����Ԫ�ظ�����1*/
			}
		}
	}
}
/*�����Ԫ���ʾt*/
static void disp_matrix(TSMatrix t)
{
	int i;
	/*�쳣���*/
	if (t.nums <= 0)
		return;
	/*�����������������*/
	printf("%d\t%d\t%d\n", t.rows, t.cols, t.nums);
	printf("------------------\n");
	/*���кż��������*/
	for (i = 0; i < t.nums; i++)
		printf("%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);
	printf("\n");
}
/*------------------------����Ԫ���ʾt��ת�þ���tb----------------------*/
/**
*   ת�þ���:
*       �Ѿ���A���л�����Ӧ���У��õ����¾����ΪA��ת�þ���
*/
static void tran_matrix(TSMatrix t, TSMatrix &tb)
{
	int p, v;
	int q = 0; // qΪtb.data���±�

	tb.rows = t.cols; // ת�þ�������ֵ
	tb.cols = t.rows; // ת�þ�������ֵ
	tb.nums = t.nums; // ת�þ������Ԫ�ظ���
	if (t.nums != 0)
	{
		for (v = 0; v < t.cols; v++) // tb.data[q]�еļ�¼��c��Ĵ�������
		{
			for (p = 0; p < t.nums; p++) // pΪt.data���±�
			{
				if (t.data[p].c == v)
				{
					tb.data[q].r = t.data[p].c; // ת�þ�����к�
					tb.data[q].c = t.data[p].r; // ת�þ�����к�
					tb.data[q].d = t.data[p].d; // ת�þ����Ԫ��ֵ
					q++;
				}
			}
		}
	}
}
/*------------------------��c=a+b----------------------*/
static bool matrix_add(TSMatrix a, TSMatrix b, TSMatrix &c) // ���������β�c
{
	int i = 0; // a�з���Ԫ�ظ�������
	int j = 0; // b�з���Ԫ�ظ�������
	int k = 0; // c�з���Ԫ�ظ���
	ElemType v;
	if (a.rows != b.rows || a.cols != b.cols) // ��������������ʱ���ܽ����������
		return false;
	// c����������a����ͬ
	c.rows = a.rows;
	c.cols = a.cols;
	while (i < a.nums && j < b.nums) // ����a��b�е�Ԫ��(���� a.nums = 6, b.nums = 4)
	{
		if (a.data[i].r == b.data[j].r) // aԪ�ص��кŵ���bԪ�ص��к�
		{
			if (a.data[i].c < b.data[j].c) // aԪ�ص��к�С��bԪ�ص��к�
			{
				// ��aԪ����ӵ�c��
				c.data[k].r = a.data[i].r;
				c.data[k].c = a.data[i].c;
				c.data[k].d = a.data[i].d;
				k++;
				i++;
			}
			else if (a.data[i].c > b.data[j].c) // aԪ�ص��кŴ���bԪ�ص��к�
			{
				// ��bԪ����ӵ�c��
				c.data[k].r = b.data[j].r;
				c.data[k].c = b.data[j].c;
				c.data[k].d = b.data[j].d;
				k++;
				j++;
			}
			else // aԪ�ص��кŵ���bԪ�ص��к�
			{
				v = a.data[i].d + b.data[j].d;
				if (v != 0) // ֻ����Ϊ0�Ľ����ӵ�c��
				{
					c.data[k].r = a.data[i].r;
					c.data[k].c = a.data[i].c;
					c.data[k].d = v;
					k++;
				}
				i++;
				j++;
			}
		}
		else if (a.data[i].r < b.data[j].r) // aԪ�ص��к�С��bԪ�ص��к�
		{
			// ��aԪ����ӵ�c��
			c.data[k].r = a.data[i].r;
			c.data[k].c = a.data[i].c;
			c.data[k].d = a.data[i].d;
			k++;
			i++;
		}
		else // aԪ�ص��кŴ���bԪ�ص��к�
		{
			// ��bԪ����ӵ�c��
			c.data[k].r = b.data[j].r;
			c.data[k].c = b.data[j].c;
			c.data[k].d = b.data[j].d;
			k++;
			j++;
		}
		c.nums = k;
	}

	return true;
}
/*------------------------������Ԫ��t��ʾ��A[i][j]ֵ----------------------*/
static int get_value(TSMatrix t, int i, int j)
{
	int k = 0;

	while (k < t.nums && (t.data[k].r != i || t.data[k].c != j))
		k++;
	if (k < t.nums)
		return t.data[k].d;
	else
		return 0;
}
/*------------------------��c=a*b----------------------*/
static bool matrix_mul(TSMatrix a, TSMatrix b, TSMatrix &c) // ���������β�c
{
	int i;
	int j;
	int k;
	int p = 0; // ����c�ķ���Ԫ�ظ���
	ElemType s;
	if (a.cols != b.rows) // a������������b������ʱ���ܽ��г˷�����
		return false;
    for (i = 0; i < a.rows; i++) // ����c������
	{
		for (j = 0; j < b.cols; j++) // ����c������
		{
			s = 0;
			for (k = 0; k < a.cols; k++)
			{
				s = s + get_value(a, i, k) * get_value(b, k, j); // ����Ԫ��Ԫ��
			}
			if (s != 0) // ����һ����Ԫ��Ԫ��
			{
				c.data[p].r = i; // ��Ԫ��Ԫ�ص��к�
				c.data[p].c = j; // ��Ԫ��Ԫ�ص��к�
				c.data[p].d = s; // ��Ԫ��Ԫ�ص�Ԫ��ֵ
				p++;
			}
		}
	}
	c.rows = a.rows;
	c.cols = b.cols;
	c.nums = p; // ����c�ķ���Ԫ�ظ���
	return true;
}
int main(void)
{
	/*����ϡ�������Ԫ��a*/
	ElemType a1[N][N] = {
		{ 1, 0, 3, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 }
	};
	/*����ϡ�������Ԫ��b*/
	ElemType b1[N][N] = {
		{ 3, 0, 0, 0 },
		{ 0, 4, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 2 }
	};
	/*������Ԫ��˳���*/
	TSMatrix a, b, c;
	/*����ϡ�����A����Ԫ��洢�ṹt*/
	create_matrix(a, a1);
	disp_matrix(a);
	/*����ϡ�����B����Ԫ��洢�ṹt*/
	create_matrix(b, b1);
	disp_matrix(b);
	/*��A��Ԫ��ת��ΪC*/
	printf("A��Ԫ��ת��ΪC\n");
	tran_matrix(a, c);
	disp_matrix(c);
	/*��Ԫ��a+b-->c*/
	printf("ʵ��c=a+b\n");
	matrix_add(a, b, c);
	disp_matrix(c);
	printf("ʵ��c=a*b\n");
	matrix_mul(a, b, c);
	disp_matrix(c);
	return 1;
}

