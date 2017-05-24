#include <iostream>
using namespace std;

class Signalleton{
public:
	static Signalleton* get_instance();
	void set_var(int var);
	int get_var();
private:
	Signalleton();
	virtual ~Signalleton();
	static Signalleton *signal;
	int _var;
};

Signalleton* Signalleton::signal = NULL;


Signalleton* Signalleton::get_instance()
{
	if (NULL == signal)
	{
		signal = new Signalleton();
	}
	return signal;
}

Signalleton::Signalleton()
{
	_var = 0;
}

Signalleton::~Signalleton()
{
	delete signal;
}

int Signalleton::get_var()
{
	return _var;
}

void Signalleton::set_var(int var)
{
	_var = var;
}

int main()
{ 
	Signalleton *s = Signalleton::get_instance();
	s->set_var(1);
	return 0;
}
