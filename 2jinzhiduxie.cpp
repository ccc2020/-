#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n=0;
	struct student
	{
		short int stu_id;
		short int score;
		
	};
    student *a=new student [n];
	student *b=new student [n];
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>a[i].stu_id>>a[i].score;
	ofstream out("out.txt",ios::binary); 
	out.write(reinterpret_cast<char *>(a), sizeof(a));
	out.close();
	ifstream in("out.txt",ios::binary); 
	for(int i=0;i<n;i++)
	    in.read(reinterpret_cast<char *>(b), sizeof(b)/sizeof(b[0]));
	out.close();
	ofstream out1("out.txt",ios::app); 
	out1.write(reinterpret_cast<char *>(b), sizeof(b));
	return 0;
	
}
