#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
class Vector
{
public:
	typedef T ValueType;
	typedef ValueType* Iterator;
	typedef const ValueType* ConstIterator;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;

	Vector();
	Vector(size_t n, const T&value = Vector());
	Vector(const Vector<T>& v);
	Vector& operator=(const Vector<T>& v);
    Iterator Begin();
	Iterator End();
	const Iterator Begin()const;
	const Iterator End()const;
	SizeType Size()const;
	SizeType Capacity()const;
	bool Empty()const;
	Reference operator[](size_t index);
	ConstReference operator[](size_t index)const;
	void PushBack(const T& value);
	void PopBack();
	Iterator Insert(Iterator pos, const T& value);
	Iterator Erase(Iterator pos);
	void Clear()const;
	void ReSize(SizeType newSize, const T& value = T());
	~Vector();
protected:
	Iterator _start;
	Iterator _finish;
	Iterator _endofStorage;
private:
	void CheckCapacity()
	{
		if ((_endofStorage - _finish)>0)
			return ;
		size_t newCapacity = Capacity()*2+1;
		size_t size = _finish - _start;
		Iterator temp = new T[newCapacity];
		if (NULL == temp)
			exit(0);
		memcpy(temp,_start,sizeof(T)*size);
		delete []_start;
		_start = temp;
		_finish = _start+size;
		_endofStorage = _start+newCapacity;
	}
};

template <class T>
Vector<T>::Vector()
:_start(0),
 _finsh(0),
 _endofStorage(0)
{}

template <class T>
Vector<T>::Vector(size_t n, const T& value)
:_start(new T[n])
{
	for (size_t i = 0; i<n; i++)
	{
		_start[i] = value; 
	}
	_finish = _start + n;
	_endofStorage = _finish;
}

template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size_t len = v._finish - v._start;
	_start = new T[len];
	for (size_t i = 0; i<len; ++i)
	{
		_start[i] = v._start[i];
	}
	_finish = _start+len;
	_endofStorage = _finish;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if(this != &v)
	{
		size_t len = v._finish - v._start;
		if (this->Capacity() >= len)
		{
			for (int i = 0; i<len; ++i)
			{
				_start[i] = v._start[i];
			}
		}
		else 
		{
			Iterator temp = new T[len];
		    delete []_start;
			_start = temp;
		}
	}
	return *this;
}

template <class T>
T* Vector<T>::Begin()
{
	return (this->_start);
}

template <class T>
T* Vector<T>::End()
{
	return (this->_finish);
}

template <class T>
T* const Vector<T>::Begin()const
{
	return (this->_start);
}

template <class T>
 T* const Vector<T>::End()const
{
	return (this->_finish);
}

template <class T>
size_t Vector<T>::Size()const
{
	return (_finish - _start);
}

template <class T>
size_t Vector<T>::Capacity()const
{
	return (_endofStorage - _start);
}

template <class T>
bool Vector<T>:: Empty()const
{
	return 0==(_finish - _start);
}

template <class T>
T& Vector<T>:: operator[](size_t index)
{
	assert(index< Size());
	return _start[index];
}

template <class T>
const T& Vector<T>::operator[](size_t index)const
{
	assert(index < Size());
	return _start[index];
}

template <class T>
void Vector<T>:: PushBack(const T& value)
{
	CheckCapacity();
	*_finish = value;
	_finish += 1;
}

template <class T>
void Vector<T>::PopBack()
{
	if (_finish - _start)
		_finish -= 1;
}

template <class T>
T* Vector<T>::Insert(Iterator pos, const T& value)
{
	CheckCapacity();
	assert(pos);
	if (pos == _finish)
		PushBack(value);
	size_t size = Size() - (pos - _start);

	for (size_t sz = size; sz>0 ; sz-- )
	{
		*(pos+sz) = *(pos+sz-1);
	}
	*pos = value;
	return pos;

}

template <class T>
T* Vector<T>::Erase(Iterator pos)
{
	assert(pos);
	if (pos == _finish)
		PopBack();
	size_t size = Size() - (pos - _start);

	for (size_t sz = 0; sz<size ; sz++ )
	{
		*(pos+sz) = *(pos+sz+1);
	}
	_finish -= 1;
	return pos;
	
}

template <class T>
void Vector<T>::Clear()const
{
	delete []_start;
	_start = NULL;
	_finish = NULL;
	_endofStorage = NULL;
}

template <class T>
void Vector<T>:: ReSize(SizeType newSize, const T& value = T())
{
    if (newSize < Size())  
    {  
        _endofStorage = _start + newSize;  
        _finish = _endofStorage;  
    }  
    else  
    {  
        Iterator Temp = new T[newSize];  
        delete []_start;  
        _start = Temp;  
        _finish = _start + newSize;  
        _endofStorage = _finish;  
    }  
    for (size_t i = 0; i <Capacity(); i++)  
    {  
        _start[i] = value;  
    }  
}

template <class T>
Vector<T>::~Vector()
{
	delete []_start;
}


template <class T>
void show(Vector<T> v)
{
	Vector<T>::Iterator it;
	for (it = v.Begin(); it < v.End(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void  Funtest1()
{
	Vector <int>v1(3,5);
	Vector <int>v2(v1);
	v2.PushBack(4);
	v1.PopBack();
	Vector<int>::Iterator it = v2.Begin() +4;
	v2.Insert(it,6);
	show(v2);
	it = v2.Begin() +3;
	v2.Erase(it);
	show(v2);
}

int main()
{
	Funtest1();
	return 0;
}