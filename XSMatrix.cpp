#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
template<typename T>
class XSMatrix
{
	template<class T>
	struct Trimat
    {
	    size_t i,j;   //行下标，列下标 
	    T e;      //元素的值 
    };
	private:
		size_t _row,_col,sum;//行数，列数，非零元素个数
		vector<Trimat<T>> data;
	public:
	    XSMatrix(int*arr,size_t row,size_t col);
	    ~XSMatrix();
	    bool Add(XSMatrix<T>&sp);
	    bool Minus(XSMatrix<T>&sp);
	    bool Multiply(XSMatrix<T>&sp);
}; 	
template<typename T>
XSMatrix<T>::XSMatrix(int*arr,size_t row,size_t col):_row(row),_col(col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;++j)
		{
			if(arr[i*col+j]!=0)
			     data.push_back(Trimat<T>(i,j,arr[i*col+j]));//将值不为0的元素的行数、列数、值存储在vector容器内 
		}
	}
}
template<typename T>
bool XSMatrix<T>::Add(XSMatrix<T>&sp)
{
	int i=0,j=0,k=0;
	T v;
	XSMatrix<T>s;
	if(this->_col!=sp._col||this->_row!=sp._row) exit();
	s._row=sp._row;
	s._col=sp._col;
	while(i<this->data.size()&&j<sp.data.size())
	 {
	 	if(this->data[i]._row==sp.data[j]._row)
	 	{
	 	    if(this->data[i]._col<sp.data[j]._col)
			{
			    s.data.push_back(Trimat<T>(this->data[i]._row,this->data[i]._col,this->data[i].e));
				i++;
				k++;	
			}
			else if(this->data[i]._col>sp.data[j]._col)
			{
			    s.data.push_back(Trimat<T>(sp.data[j]._row,sp.data[j].col,sp.data[j].e));
				j++;
				k++;	
		    }
			else
			{
				v=this->data[i].e+sp.data[j].e;
				if(v)
				{
					s.data.push_back(Trimat<T>(sp.data[j]._row,sp.data[j]._col,v));
					k++;
				}
				i++;
				j++;
			}	
		}
		else if(this->data[i]._row<sp.data[j]._row)
		{
			s.data.push_back(Trimat<T>(this->data[i]._row,this->data[i]._col,this->data[i].e));
			i++;
			k++;
		}
		else
		{
			s.data.push_back(Trimat<T>(sp.data[j]._row,sp.data[j]._col,sp.data[j].e));
			j++;
			k++;
		}
	 }
	return s;
}


int main()
{
	
}
