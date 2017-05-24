#include <iostream>
using namespace std;

typedef int DataType;

struct Node
{
	Node(const DataType& data)
		:_data(data)
		,_pre(NULL)
		,_next(NULL)
	{}
	DataType _data;
	Node* _pre;
	Node* _next;
};

class List
{
public:
	explicit List()
		:_pHead(NULL)
		,_pTail(NULL)
		,_size(0)
	{}
    friend ostream& operator <<(ostream& cout,const List l)
	{
			Node* pTemp = l._pHead;
			while (pTemp)
			{
				cout<<pTemp->_data<<"->";
				pTemp = pTemp->_next;
		}
			cout<<"NULL"<<endl;
			return cout;

	}

	List(size_t n, const DataType& data = DataType())   //创建一个由n个data构成的节点
	{
		if (n>0)
		{
			_size = 1;
			_pHead =  new Node(data);
			Node* pTemp = _pHead;
			while (--n)
			{
				pTemp ->_next = new Node (data);
				pTemp ->_next ->_pre = pTemp ;
				pTemp = pTemp ->_next ;
				_size ++;

			}
			_pTail = pTemp;	
		}
	}

	List(const List& l)
	:_pHead(NULL)
	,_pTail(NULL)
	,_size()
	{
		_CopyList(l._pHead);

	}

	List& operator=(const List& l)
	{
		if (this != &l)
		{
			List ltemp(l);
			return ltemp;
		}
	}


	~List()
	{
	    _DestroyList();
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return (0 == _size);
	}

	Node& Front()
	{
		return *_pHead;
	}

	const Node& Front()const
	{
		return *_pHead;
	}

	Node& Back()
	{
		return *_pTail;
	}

	const Node& Back()const
	{
		return *_pTail;
	}

	void Assign(size_t n, const DataType& data)  //为list重新开辟空间并赋值，n个datatype类型的data
	{
		if (n<0)
			return ;
		_size = 1;
		_pHead =  new Node(data);
		Node* pTemp = _pHead;
		while (--n)
		{
			pTemp ->_next = new Node (data);
			pTemp ->_next ->_pre = pTemp ;
			pTemp = pTemp ->_next ;
			_size ++;

		}
		_pTail = pTemp;	
	}

	void Assign(Node* first, Node* second)  //复制一个节点到另一个节点的链表给一个新空间
	{
		if (NULL == first || NULL == second)
			return ;

		_pHead = new Node(first ->_data);
         Node* pTemp = _pHead;
		 _size = 1 ;
		 while (first != second)
		 {
			 first = first->_next;
			 pTemp ->_next = new Node(first->_data);
			 pTemp ->_next ->_pre = pTemp;
			 pTemp = pTemp ->_next;
             _size ++;
		 }
		 _pTail = pTemp;
		
	}

	void PushBack(const DataType& data)  //尾插
	{ 
		if (NULL == _pHead)
		{
			_pHead = new Node (data);
			_pTail = _pHead ;
			_size = 1;
		}
		else 
		{
			_pTail ->_next = new Node(data);
			_pTail ->_next ->_pre = _pTail;
			_pTail = _pTail->_next;
			_size ++ ;
		}
	}

	void PopBack()   //尾删
	{
		if (NULL == _pHead)
			return;
		else  if (_size == 1)
		{
			delete (_pHead);
			_pHead = NULL;
			_pTail = NULL;
			_size = 0;

		}
		else 
		{
			_pTail = _pTail ->_pre;
			_pTail ->_next = NULL;
			_size --;
		}

	}
	void PushFront(const DataType& data)  //头插
	{
		if (NULL == _pHead)
		{
			_pHead = new Node (data);
			_pTail = _pHead ;
			_size = 1;
		}
		else 
		{
			_pHead ->_pre = new Node(data);
			_pHead ->_pre ->_next = _pHead;
			_pHead = _pHead->_pre;
			_size ++ ;
		}
	}

	void PopFront()
	{	
		if (NULL == _pHead)
			return;
		else  if (_size == 1)
		{
			delete (_pHead);
			_pHead = NULL;
			_pTail = NULL;
			_size = 0;

		}
		else 
		{
			_pHead = _pHead ->_next;
			_pHead ->_pre = NULL;
			_size --;
		}
	}

	Node* Find(const DataType& data)
	{
		Node* pTemp = _pHead;
		while (pTemp)
		{
			if (pTemp->_data == data)
				return pTemp;
			pTemp = pTemp->_next;
		}

		return NULL;

	}

	void Insert(Node* pos, const DataType& data)
	{
		if (NULL == pos)
			return;
		else if(_pHead == pos)
		{
			pos = new Node(data);
			pos ->_next = _pHead;
			_pHead ->_pre = pos;
			_pHead = pos;
			_size ++;
		}
		else
		{
           Node* pTemp = new Node(data);
		   pos->_pre ->_next = pTemp;
		   pTemp ->_pre = pos->_pre;
		   pTemp ->_next = pos;
		   pos ->_pre = pTemp;

		   _size ++;
		}

	}
	void Erase(Node* pos)
	{
		if (NULL == pos)
			return;
		if (pos==_pHead)
			PopFront();
		else if (pos == _pTail)
			PopBack();
		else
		{
			pos ->_pre->_next = pos ->_next;
			pos ->_next ->_pre = pos ->_pre;
			_size --;
		}
	}

private:
	void _CopyList(Node* pos)
	{
		if (NULL == pos)
			return ;
		_pHead = new Node(pos ->_data);
		_size = 1;
		Node* pTemp = _pHead ;
		while (pos ->_next)
		{
			pos = pos ->_next;
			pTemp ->_next = new Node(pos->_data);
			pTemp ->_next ->_pre = pTemp;
			pTemp = pTemp ->_next;
			_size ++;
		}
		_pTail = pTemp;
	}

	void _DestroyList()
	{
		if (NULL == _pHead)
			return ;
		while (_pTail != _pHead)
		{
			_pTail = _pTail ->_pre;
			delete (_pTail ->_next);
			_pTail ->_next = NULL;
		}

		delete _pHead;
		_pHead = NULL;
		_pTail = NULL;
		_size = 0;
	}

	

private:
	Node* _pHead;
	Node* _pTail;
	size_t _size;
};

int main()
{
	List l1(5,1);
	//List l2(l1);
	List l2;
	l2.Assign(&l1.Front(),&l1.Back());
    List l3 (l2);
	l3.PushBack(2);
	l3.PopFront();
	l3.PopFront();
	l3.PopFront();
	l3.PushBack(5);

	l3.PushBack(6);
	l3.PushBack(3);

	l3.PushBack(4);
	Node* ret = l3.Find(6);
	l3.Erase(ret);
	List l4 = l3;
	cout<<l4;


	return  0;
}

