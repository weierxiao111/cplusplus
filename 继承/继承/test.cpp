#include <iostream>
using namespace std;


class Test1
{
public:
Test1( int data){cout <<"Test1()"<<endl;}
~Test1 (){cout<< "~Test1()"<<endl ;}
};
class Test2
{
public:
Test2( int data){cout <<"Test2()"<<endl;}
~Test2 (){cout<< "~Test2()"<<endl ;}
};

class Base1
{
public:
Base1( int data): _data(data )
{cout <<"Base1()"<<endl;}
~Base1 (){cout<< "~Base1()"<<endl ;}
protected:
int _data;
};

class Base2
{
public:
Base2( int data): _data2(data )
{cout <<"Base2()"<<endl;}
~Base2 (){cout<< "~Base2()"<<endl ;}
protected:
int _data2;
};

class Derive: public Base1, public Base2
{
public:
//Derive(): Base1(0), Base2(1),t1(3), t2(4)
//Derive(): Base2(0), Base1(1),t2(3), t1(4)
//Derive(): t1(3), t2(4), Base1(0), Base2(1)
Derive(): t2 (3), t1 (4), Base2 (0), Base1(1 )
{cout <<"Derive()"<<endl;}
~Derive (){cout<< "~Derive()"<<endl ;}
protected:
Test1 t1;
Test2 t2;
};int main(){	Derive d1();	return 0;}