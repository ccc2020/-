#include <iostream>	
#include <string.h> 
#include <cstdlib>
using namespace std; 
int main()
{
	char a[10],b[10];
	int i,j,len1,len2,min=26;
	cin>>a;
	cin>>b;
	len1=strlen(a);
	len2=strlen(b);
	for(i=0;i<len1;i++)
	  if(a[i]>='A'&&a[i]<='Z') a[i]=a[i]+32;
	for(i=0;i<len2;i++)
	  if(b[i]>='A'&&b[i]<='Z') b[i]=b[i]+32;
	for(i=0;i<len1;i++)
	   for(j=0;j<len2;j++)
	       if(abs(a[i]-b[j])<min)min=abs(a[i]-b[j]);
	cout<<min;
	return 0;
} 
