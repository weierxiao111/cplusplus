#include <iostream>
using namespace std;

typedef void (* pFun)(void);
class Base{
public:
	Base():b(10){};
	virtual void e(){ cout<<"B1:: e()       "<<endl;}
	virtual void f(){ cout<<"B1:: f()       "<<endl;}
	virtual void g(){ cout<<"B1:: g()       "<<endl;}
public:
	int b;

};

class C1: virtual public Base{
public:
	C1():c1(20){};
	virtual void i(){ cout<<"C1:: i()       "<<endl;}
public:
	int c1;
};

class C2: virtual public Base{
public:
	C2():c2(30){};
	virtual void j(){ cout<<"C2:: j()       "<<endl;}
public:
	int c2;

};

class C3: virtual public Base{
public:
	C3():c3(30){};
	virtual void k(){ cout<<"C3:: k()       "<<endl;}
public:
	int c3;
};


class Derive: public C1,public C2,public C3{
public:
	Derive():d(50){cout<<"sizeof(Derive) is : "<<sizeof(Derive)<<endl;}
	virtual void h(){cout<<"D::h()"<<endl;}
public:
	int d;

};

int main()
{
	Derive dd;

	return 0;
}

//for (int i=0; i<4; i++)
	//{
	//    pFun fun = (pFun)* ((int*)*(int*)&derive + i);
	//    fun();
	//}
	//
