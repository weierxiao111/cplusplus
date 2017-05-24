#include <iostream>
#include "Vector.h"

using namespace std;

template <class T>
class Vector{
public:
	typedef T ValueType;
	typedef ValueType* Iterator;
	typedef const ValueType* constIterator;
	typedef ValueType& Reference;
	typedef const ValueType& constReference;
	typedef size_t SizeType;

	Vector();
	Vector(size_t n, const T& value = Vector());
	~Vector();

protected:
	Iterator _start;
	Iterator _finish;
	Iterator _endofStorage;
};


void Funtest1()
{
	Vector<int>v(2,3);
}
int main()
{
	Funtest1();
	return 0;
}