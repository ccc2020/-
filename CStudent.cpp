#include  <iostream> 
#include  <string> 
using  namespace  std; 

class  CStudent 
{ 
  public:
        CStudent(){
        name="\0";
        age=0;
        count++;
        cout<<"noname is contructing"<<endl;	
}
   	CStudent(std::string name0,int age0){

	name=name0;
	age=age0;
	count++;	
       	cout<<name<<" "<<"is contructing"<<endl;	
    
}
   	~CStudent(){
	count--;
	if(name=="\0")
    	cout<<"noname is destructing"<<endl;	
    else
       	cout<<name<<" "<<"is destructing"<<endl;	
}
static int getcount(){
	return count;
}
void printname(){
        if(age==0) cout<<"name:noname"<<endl;
	else cout<<"name:"<<name<<endl;
}
 
	
   private:
   	 string name;
   	 int age;
	 static int count;

}; 
//请在这里初始静态成员变量 
 
int CStudent::count=0;
int  main() 
{ 
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        { 
                CStudent  stuB[5]; 
                stuB[4].printname(); 
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        } 
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        { 
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)}; 
                for  (int  i  =  0;  i  <  2;  i++) 
                { 
                        stuA[i].printname(); 
                } 
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        } 
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 

        return  0; 
}


