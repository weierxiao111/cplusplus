#include <iostream>
using namespace std;

class Base{
public:
	void f(float x){cout<<"Base::f(float)   "<<x<<endl;} //
	void g(float x){cout<<"Base::g(float)   "<<x<<endl;}
	virtual void h(void){cout<<"Base::h(void)   "<<endl;}
};

class Derive: public Base
{
public:
	void f(float x){cout<<"Derive::f(float)   "<<x<<endl;}
	void g(int x){cout<<"Derive::g(int)   "<<x<<endl;}
	virtual void h(void){cout<<"Derive::h(void)   "<<endl;}
};

int main()
{
	Derive d;
	Base* pb = &d;
	Derive* pd = &d;
	pb->f(1.23f);
	pd->f(1.23f);

	pb->g(1.23f);
	pd->g(1.23f);

	pb->h();
	pd->h();

	return 0;
}