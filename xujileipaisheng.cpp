#include  "iostream" 
using  namespace  std; 
class vehicle
{
	private:
		int maxspeed,weight;
	public:
		void run(){cout<<"vehicle run"<<endl;}
		void stop(){cout<<"vehicle stop"<<endl;}
		vehicle(int i,int j);
		~vehicle();
};
vehicle::vehicle(int i,int j)
{
	maxspeed=i;
	weight=j;
	cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<";"<<" weight"<<weight<<endl;
}
vehicle::~vehicle()
{
	cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<";"<<" weight"<<weight<<endl;
}
class bicycle:virtual public vehicle
{
	private:
		int height;
	public:
		bicycle(int i,int j,int k);
		~bicycle();
};
bicycle::bicycle(int i,int j,int k):vehicle(j,k)
{
	height=i;
	cout<<"bicycle constructor called. height:"<<height<<endl; 
}
bicycle::~bicycle()
{
	cout<<"bicycle destructor called. height:"<<height<<endl;
}
class motorcar:virtual public vehicle
{
	private:
		int seatnum;
	public:
		motorcar(int i,int j,int k);
		~motorcar();
};
motorcar::motorcar(int i,int j,int k):vehicle(j,k)
{
	seatnum=i;
	cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
	cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;
}
class motorcycle:public bicycle,public motorcar
{
	public:
		motorcycle(int i,int j,int k,int h);
		~motorcycle();
};
motorcycle::motorcycle(int i,int j,int k,int h):vehicle(k,h),bicycle(i,k,h),motorcar(j,k,h)
{
	cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
	cout<<"motorcycle destructor called"<<endl;
} 
int  main(int  argc,  char  *argv[]) 
{ 
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
        m.run(); 
        m.stop(); 
        return  0; 
}
