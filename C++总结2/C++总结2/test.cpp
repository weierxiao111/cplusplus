#include <iostream>
using namespace std;

class St{
public:
	St(){cout<<"St"<<endl;}
	void fun(){
		cout<<(St*)this<<endl;
		cout<<"fun"<<endl;
	}
	 static void Ss()
	 {
		 St();
	 }
};
int main()
{
	St s;
	St::Ss();
	s.fun();
	return 0;
}