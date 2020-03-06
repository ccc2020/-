#include <iostream>
#include <iomanip>
using namespace std; 

void plural(float x[2],float y[2],float z[2]);
int main() 
{ float a[2],b[2],c[2];
  int i;
  for(i=0;i<2;i++)
     c[i]=0.0;
  cin>>a[0]>>a[1]>>b[0]>>b[1];
  plural(a,b,c);
  for(i=0;i<2;i++)
  cout<<setiosflags(ios::fixed)<<setprecision(2)<<c[i]<<" ";
	
	
	return 0;
}
void plural(float x[2],float y[2],float z[2])
{
	int j;
	for(j=0;j<2;j++)
	    z[j]=x[j]-y[j];
	    
	    
}
