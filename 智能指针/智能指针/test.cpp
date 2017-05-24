#include <iostream>
using namespace std;

template <class T> class Smart_ptr ;

template <class T>
class Refptr{
private:
	friend class Smart_ptr<T>;
	Refptr(T* ptr)
		: p(ptr)
		,ref(1)
	{}
	~Refptr()
	{
		delete p;
	}
    Refptr(const Refptr<T>& r);
	Refptr& operator = (const Refptr<T>& r);
	int ref;
	T* p;
};

template <class T>
class Smart_ptr{
public:
	Smart_ptr(T* ptr = NULL)
		:_p(new Refptr<T>(ptr))  //构造辅助类对象来初始化指针
	{}
	Smart_ptr(const Smart_ptr<T>& s)
		:_p(s._p)
	{
		++s._p->ref;  
	}
	Smart_ptr& operator =(const Smart_ptr<T>& s)
	{
		if (this != &s)
		{
			++s._p->ref;      
			if (--_p->ref == 0)   
				delete _p;
			_p = s._p;
		}
		return *this;
	}

	T& operator *() 
	{
		return *(_p->p);
	}

	T& operator ->() 
	{
		return _p->p;
	}
	int useRef()
	{
		return _p->ref;
	}
	~Smart_ptr()
	{
		if ( -- _p->ref == 0)
		{
			delete _p;
		cout<<"指针被析构了"<<endl;
		}
		else 
			cout<<"还有"<<_p->ref<<"个"<<"指针使用它"<<endl;
	}
private:
		Refptr<T> *_p;
		
};

struct ListNode{
	Smart_ptr<ListNode> _next;
	Smart_ptr<ListNode> _pre;
	~ListNode(){
		cout<<"~ListNode"<<endl;
	}
};

void Funtest1()
{
	Smart_ptr<ListNode> p1(new ListNode());
	Smart_ptr<ListNode> p2(new ListNode());

	cout<<"还有"<<p1.useRef()<<"个指针指向p1"<<endl;
	cout<<"还有"<<p2.useRef()<<"个指针指向p2"<<endl;

	p1 ->_next = p2;
	p2 ->_pre = p1;
	cout<<"还有"<<p1.useRef()<<"个指针指向p1"<<endl;
	cout<<"还有"<<p2.useRef()<<"个指针指向p2"<<endl;

}

int main()
{
	Funtest1();
	return 0;
}


