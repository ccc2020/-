#include  <iostream>
#include  <iomanip>
using  namespace  std;
//请在此处补充Account类的定义
class Account{
	public:
		void init(string id1,string name1,string sex1,int age1,double money1);
		void printmoney();
		void withdraw(double m1);
		void deposit(double m2);
    private:
    	string id,name,sex;
    	int age;
    	double money;
    	
};
void Account::init(string id1,string name1,string sex1,int age1,double money1)
{
    id=id1;
	name=name1;
	sex=sex1;
	age=age1;
	if(money1-(int)(money1*100)/100.0==0) money=money1;
	else cout<<"您输入的金额不合法 "<<endl;
}
void Account::printmoney()
{   
     cout<<name<<"的存款为"<<fixed<<setprecision(2)<<money<<endl;
  
}
void Account::withdraw(double m1)
{       
   
      if(m1-(int)(m1*100)/100.0!=0) cout<<"您输入的金额不合法 "<<endl;
       else   {	if(money>=m1) money=money-m1;	                    
	            else  cout<<"您的存款金额不足"<<endl;}
   
}
void Account::deposit(double m2)
{
	if(m2-(int)(m2*100)/100.0==0)
	  money=money+m2;	
	else cout<<"您输入的金额不合法 "<<endl;
}
int  main()
{
        Account  tom;
        tom.init("32020320011001876X",  "Tom  Black",  "男",  19,  2000.89);
        tom.printmoney();//输出：Tom  Black的存款为2000.89
        tom.deposit(89.471);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的存款为2000.89
        tom.deposit(10000);
        tom.printmoney();//输出：Tom  Black的存款为12000.89
        tom.withdraw(10001);
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        tom.withdraw(10000.123);//输出：您输入的金额不合法
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        tom.withdraw(10000.9);//输出：您的存款金额不足
        tom.printmoney();//输出：Tom  Black的存款为1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法
        jerry.printmoney();//输出：Jerry  Black的存款为0.00
}

