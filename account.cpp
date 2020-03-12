#include  <iostream>
#include  <iomanip>
using  namespace  std;
//���ڴ˴�����Account��Ķ���
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
	else cout<<"������Ľ��Ϸ� "<<endl;
}
void Account::printmoney()
{   
     cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<money<<endl;
  
}
void Account::withdraw(double m1)
{       
   
      if(m1-(int)(m1*100)/100.0!=0) cout<<"������Ľ��Ϸ� "<<endl;
       else   {	if(money>=m1) money=money-m1;	                    
	            else  cout<<"���Ĵ�����"<<endl;}
   
}
void Account::deposit(double m2)
{
	if(m2-(int)(m2*100)/100.0==0)
	  money=money+m2;	
	else cout<<"������Ľ��Ϸ� "<<endl;
}
int  main()
{
        Account  tom;
        tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89);
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
        tom.deposit(89.471);//�����������Ľ��Ϸ�
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
        tom.deposit(10000);
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89
        tom.withdraw(10001);
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
        tom.withdraw(10000.123);//�����������Ľ��Ϸ�
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
        tom.withdraw(10000.9);//��������Ĵ�����
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
        Account  jerry;
        jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ�
        jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00
}

