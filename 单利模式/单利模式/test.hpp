#include <iostream>
using namespace std;

template <class T>
class Signalleton{
public:
	static Signalleton* get_instance();
	void set_var(T var);
	T get_var();
private:
	Signalleton();
	virtual ~Signalleton();
	static Signalleton *signal;
	T _var;
};


template <class T>
Signalleton<T>* Signalleton::signal = NULL;

template <class T>
Signalleton<T>* Signalleton::get_instance()
{
	if (NULL == signal)
	{
		signal = new Signalleton();
	}
	return signal;
}

template <class T>
Signalleton<T>::Signalleton()
{
	_var = 0;
}

template<class T>
Signalleton<T>::~Signalleton()
{
	delete signal;
}

template <class T>
T Signalleton<T>::get_var()
{
	return _var;
}

template <class T>
void Signalleton<T>::set_var(T var)
{
	_var = var;
}