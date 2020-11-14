#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define N 4
#define MAX_SIZE 100 // 矩阵中非零元素最多个数
typedef int ElemType;
/*
在矩阵中，若数值为0的元素数目远远多于非0元素的数目，并且非0元素分布没有规律时，则称该矩阵为稀疏矩阵；
与之相反，若非0元素数目占大多数时，则称该矩阵为稠密矩阵。
*/
/*三元组定义*/
typedef struct
{
	int r; /*行号*/
	int c; /*列号*/
	ElemType d; /*元素值*/
}TupNode; 
 /*三元组存储结构顺序表定义*/
typedef struct
{
	int rows; // 行数值
	int cols; // 列数值
	int nums; // 非零元素个数
	TupNode data[MAX_SIZE];
}TSMatrix; 
/*产生稀疏矩阵A的三元组的顺序表存储结构t*/
static void create_matrix(TSMatrix &t, ElemType A[N][N])
{
	int i, j;

	t.rows = N; /* 行数赋值*/
	t.cols = N; /* 列数赋值*/
	t.nums = 0; /*非零元素个数初始化*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (A[i][j] != 0)
			{
				t.data[t.nums].r = i; /*行号*/
				t.data[t.nums].c = j; /*列号*/
				t.data[t.nums].d = A[i][j]; /*元素值*/
				t.nums++; /*非零元素个数增1*/
			}
		}
	}
}
/*输出三元组表示t*/
static void disp_matrix(TSMatrix t)
{
	int i;
	/*异常打回*/
	if (t.nums <= 0)
		return;
	/*行列数与非零个数输出*/
	printf("%d\t%d\t%d\n", t.rows, t.cols, t.nums);
	printf("------------------\n");
	/*行列号及数据输出*/
	for (i = 0; i < t.nums; i++)
		printf("%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);
	printf("\n");
}
/*------------------------求三元组表示t的转置矩阵tb----------------------*/
/**
*   转置矩阵:
*       把矩阵A的行换成相应的列，得到的新矩阵称为A的转置矩阵。
*/
static void tran_matrix(TSMatrix t, TSMatrix &tb)
{
	int p, v;
	int q = 0; // q为tb.data的下标

	tb.rows = t.cols; // 转置矩阵行数值
	tb.cols = t.rows; // 转置矩阵列数值
	tb.nums = t.nums; // 转置矩阵非零元素个数
	if (t.nums != 0)
	{
		for (v = 0; v < t.cols; v++) // tb.data[q]中的记录以c域的次序排列
		{
			for (p = 0; p < t.nums; p++) // p为t.data的下标
			{
				if (t.data[p].c == v)
				{
					tb.data[q].r = t.data[p].c; // 转置矩阵的行号
					tb.data[q].c = t.data[p].r; // 转置矩阵的列号
					tb.data[q].d = t.data[p].d; // 转置矩阵的元素值
					q++;
				}
			}
		}
	}
}
/*------------------------求c=a+b----------------------*/
static bool matrix_add(TSMatrix a, TSMatrix b, TSMatrix &c) // 引用类型形参c
{
	int i = 0; // a中非零元素个数索引
	int j = 0; // b中非零元素个数索引
	int k = 0; // c中非零元素个数
	ElemType v;
	if (a.rows != b.rows || a.cols != b.cols) // 行数或列数不等时不能进行相加运算
		return false;
	// c的行列数与a的相同
	c.rows = a.rows;
	c.cols = a.cols;
	while (i < a.nums && j < b.nums) // 处理a和b中的元素(假设 a.nums = 6, b.nums = 4)
	{
		if (a.data[i].r == b.data[j].r) // a元素的行号等于b元素的行号
		{
			if (a.data[i].c < b.data[j].c) // a元素的列号小于b元素的列号
			{
				// 将a元素添加到c中
				c.data[k].r = a.data[i].r;
				c.data[k].c = a.data[i].c;
				c.data[k].d = a.data[i].d;
				k++;
				i++;
			}
			else if (a.data[i].c > b.data[j].c) // a元素的列号大于b元素的列号
			{
				// 将b元素添加到c中
				c.data[k].r = b.data[j].r;
				c.data[k].c = b.data[j].c;
				c.data[k].d = b.data[j].d;
				k++;
				j++;
			}
			else // a元素的列号等于b元素的列号
			{
				v = a.data[i].d + b.data[j].d;
				if (v != 0) // 只将不为0的结果添加到c中
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
		else if (a.data[i].r < b.data[j].r) // a元素的行号小于b元素的行号
		{
			// 将a元素添加到c中
			c.data[k].r = a.data[i].r;
			c.data[k].c = a.data[i].c;
			c.data[k].d = a.data[i].d;
			k++;
			i++;
		}
		else // a元素的行号大于b元素的行号
		{
			// 将b元素添加到c中
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
/*------------------------返回三元组t表示的A[i][j]值----------------------*/
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
/*------------------------求c=a*b----------------------*/
static bool matrix_mul(TSMatrix a, TSMatrix b, TSMatrix &c) // 引用类型形参c
{
	int i;
	int j;
	int k;
	int p = 0; // 矩阵c的非零元素个数
	ElemType s;
	if (a.cols != b.rows) // a的列数不等于b的行数时不能进行乘法运算
		return false;
    for (i = 0; i < a.rows; i++) // 矩阵c的行数
	{
		for (j = 0; j < b.cols; j++) // 矩阵c的列数
		{
			s = 0;
			for (k = 0; k < a.cols; k++)
			{
				s = s + get_value(a, i, k) * get_value(b, k, j); // 求三元组元素
			}
			if (s != 0) // 产生一个三元组元素
			{
				c.data[p].r = i; // 三元组元素的行号
				c.data[p].c = j; // 三元组元素的列号
				c.data[p].d = s; // 三元组元素的元素值
				p++;
			}
		}
	}
	c.rows = a.rows;
	c.cols = b.cols;
	c.nums = p; // 矩阵c的非零元素个数
	return true;
}
int main(void)
{
	/*生成稀疏矩阵三元组a*/
	ElemType a1[N][N] = {
		{ 1, 0, 3, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 }
	};
	/*生成稀疏矩阵三元组b*/
	ElemType b1[N][N] = {
		{ 3, 0, 0, 0 },
		{ 0, 4, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 2 }
	};
	/*定义三元组顺序表*/
	TSMatrix a, b, c;
	/*产生稀疏矩阵A的三元组存储结构t*/
	create_matrix(a, a1);
	disp_matrix(a);
	/*产生稀疏矩阵B的三元组存储结构t*/
	create_matrix(b, b1);
	disp_matrix(b);
	/*将A三元组转置为C*/
	printf("A三元组转置为C\n");
	tran_matrix(a, c);
	disp_matrix(c);
	/*三元组a+b-->c*/
	printf("实现c=a+b\n");
	matrix_add(a, b, c);
	disp_matrix(c);
	printf("实现c=a*b\n");
	matrix_mul(a, b, c);
	disp_matrix(c);
	return 1;
}

