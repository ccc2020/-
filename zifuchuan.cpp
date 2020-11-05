#include<iostream>
#include<string.h>
using namespace std;
class String
{
	public:
		String(const char*str);
		int Strassign(String str);//赋值
		String subString(int pos,int n);//求字符串第pos个字符起，长度为n的子串 
		String &operator+=(const String &str);//将一个字符串拼接到另一个之后 
		int insertStr(String str,int pos);//在字符串第pos个位置插入字符串str 
		char&operator[](int n)const;//重载[] 
	    int size();
	    void clear();
	    friend istream&operator>>(istream&is,String&str);//重载>>
		friend ostream&operator<<(ostream&os,String&str);//重载<< 
	private:
		char*m_data;
		int m_size;
};
String::String(const char*str)
{
	int n=0;
	while(str[n++]);
	n--;
	m_data=new char[n+1]; 
	if(!m_data)throw"Error!";
	for(int i=0;i<=n;i++) m_data[i]=str[i];
	m_size=n;
}
int String::size()
{
	return m_size;
}
inline char&String::operator[](int n)const
{
	if(n>=m_size) return m_data[m_size-1];
	else return m_data[n];
}
String String::subString(int pos,int n)
{
	char*p=new char[n+1];
	if(!p) return String("");
	if(pos+n>m_size) return String("");
	for(int i=0,j=pos;i<=n;i++,j++)
	      p[i]=m_data[j];
	String str(p);
	delete[]p;
	return str;
}
String&String::operator+=(const String &str)
{
	int new_size=m_size+str.m_size;
	char *p=new char[new_size+1];
	if(!p) return *this;
	int i=0;
	while(i<m_size){
		p[i]=m_data[i];
		i++;
	}
	for(int j=0;j<=str.m_size;j++,i++)
	    p[i]=str[j];
	delete[]m_data;
	m_data=p;
}
int String::insertStr(String str,int pos)
{
	if(pos<1)  return 0;
	else
	{
		int k=0;
		int i=0;
		int new_size=m_size+str.m_size;
		char *p=new char[new_size+1];
		for(;i<pos-1;i++)
		       p[i]=m_data[i];
		k=i;
		for(int j=0;j<str.m_size;j++,i++)
		   p[i]=str[j];
		for(;i<=new_size;i++,k++)
		       p[i]=m_data[k];
		delete[]m_data;
		m_data=p;
		m_size=new_size;
	    return 1;
	}
}
int String::Strassign(String str)
{
	if(m_data) delete[]m_data;
	if(str.size()==0)
    {
        m_data=NULL;
		m_size=0;
		return 1;      	
	}	
	else
	{
		m_data=new char[str.size()+1];
		if(m_data==NULL) return 0;
		else
		{
		    
			for(int i=0;i<str.size();i++)
			    m_data[i]=str[i];
			m_size=str.size();
			return 1;	
		} 
	}
}
void String::clear()
{
	if(m_data) delete[]m_data;
	m_size=0;
}
istream&operator>>(istream&is,String &str)
{
	char tem[1000];
	is>>tem;
	str.m_size=strlen(tem);
	str.m_data=new char[str.m_size+1];
	strcpy(str.m_data,tem);
	return is;
}
ostream&operator<<(ostream&os,String&str)
{
	os<<str.m_data;
	return os;
}
int main()
{
	String S("abcdef");
	cout<<S.size()<<endl;
	S.insertStr("zxy",1);
	cout<<S<<endl;
	cout<<S.size()<<endl;
	S.Strassign("cccc");
	cout<<S<<endl;
}































