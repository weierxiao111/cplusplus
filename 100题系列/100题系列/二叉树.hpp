#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <stack>

template <typename T>
struct TreeNode {
	TreeNode(const T& value)
		:_value(value)
		, _pLeft(NULL)
		, _pRight(NULL)
	{}
	TreeNode<T> *_pLeft;
	TreeNode<T> *_pRight;
	T _value;
};

template <typename T>
class BinaryTree {
	typedef TreeNode<T> Node;
public:
	BinaryTree()
		:_pRoot(NULL)
	{}

	BinaryTree(const T* arr,  int sz, const T& invalied )  //����һ��˳��Ϊǰ������飬invalied��ζ�ڵ�ΪNULL
	{
		int index = 0;
		createTree(arr, _pRoot, sz, invalied, index);
	}

	BinaryTree(const BinaryTree<T>& t)
	{
		_pRoot = _CopyTree(t._pRoot);
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		_DestroyTree(_pRoot);
		_pRoot = _CopyTree(t._pRoot);
		return *this;
	}

	Node* GetRoot()
	{
		return _pRoot;
	}

	void PreOrder()  //ǰ�����
	{
		cout << "ǰ����ʣ�";
		_PreOrder(_pRoot);
		cout << "end" << endl;
	}

	void InOrder() //�������
	{
		cout << "������ʣ�";
		_InOrder(_pRoot);
		cout << "end" << endl;
	}

	void PostOrder() //�������
	{
		cout << "������ʣ�";
		_PostOrder(_pRoot);
		cout << "end" << endl;
	}

	void LeverOrder() //�������
	{
		cout << "������ʣ�";
		queue<Node*> q;
		if (_pRoot)
		{
			q.push(_pRoot);
			_LeverOrder(_pRoot, q);
		}
	}

	Node* GetParent(Node* x) //�õ����ڵ�
	{
		if (_pRoot == NULL)
			return _pRoot;
		return _GetParent(_pRoot, x);
	}

	Node* Find(const T& value) //���ҽ��
	{
		return _FindNode(_pRoot, value);
	}

	size_t Hight()  //�����ĸ߶�
	{
		return _Hight(_pRoot);
	}

	size_t GetLeefNode() //��Ҷ�ӽڵ�ĸ���
	{
		return _GetLeefNode(_pRoot);
	}

	size_t GetLevelNode(size_t k)   //���K��ڵ�ĸ���
	{
		return _GetLevelNode(_pRoot, k);
	}

	void PreOrder_Nor()   //ǰ�����(���õݹ�)
	{
		if (_pRoot)
			_PreOrder_Nor(_pRoot);
	}

	void InOrder_Nor()   //������������õݹ飩
	{
		if (_pRoot)
			_InOrder_Nor(_pRoot);
	}

	void PostOrder_Nor()   //������������õݹ飩
	{
		if (_pRoot)
			_PostOrder_Nor(_pRoot);
	}

	void GetBinaryMirror()   //��������ľ���
	{
		if (_pRoot)
			_GetBinaryMirror(_pRoot);
	}

	void GetBinaryMirror_Nor()   //��������ľ��񣨷ǵݹ飩
	{
		if (_pRoot)
			_GetBinaryMirror(_pRoot);
	}

	bool isCompleteBinaryTree()   //�ж��Ƿ�Ϊ��ȫ������
	{
		if (_pRoot)
		{
			queue<Node*> q;
			q.push(_pRoot);
			bool isComplete = true;
			while (!q.empty())
			{
				Node* Front = q.front();
				q.pop();
				if (!isComplete && (Front->_pLeft || Front->_pRight))
				{
					return false;
				}
				if (Front->_pLeft)
					q.push(Front->_pLeft);
				if (Front->_pRight)
					q.push(Front->_pRight);
				else
				{
					isComplete = false;
				}
			}
			return true;
		}
		return false;
	}

	~BinaryTree()
	{
		_DestroyTree(_pRoot);
	}

private:
	void createTree(const T* arr, Node* &proot, size_t size,
		const T& invalied, int& index)
	{
		if (index < size && arr[index] != invalied)
		{
			proot = new Node(arr[index]);
			createTree(arr, proot->_pLeft, size, invalied, ++index);
			createTree(arr, proot->_pRight, size, invalied, ++index);
		}
	}

	Node *_CopyTree(Node* proot)
	{
		if (proot)
		{
			Node *temp = new Node(proot->_value);
			temp->_pLeft = _CopyTree(proot->_pLeft);
			temp->_pRight = _CopyTree(proot->_pRight);
			return temp;
		}
		return NULL;
	}

	void _DestroyTree(Node *&proot)
	{
		if (proot)
		{
			_DestroyTree(proot->_pLeft);
			_DestroyTree(proot->_pRight);
			delete proot;
			proot = NULL;
		}
	}

	void _PreOrder(Node* proot)
	{
		if (proot)
		{
			cout << proot->_value << "->";
			_PreOrder(proot->_pLeft);
			_PreOrder(proot->_pRight);
		}
	}

	void _InOrder(Node *proot)
	{
		if (proot)
		{
			_InOrder(proot->_pLeft);
			cout << proot->_value << "->";
			_InOrder(proot->_pRight);
		}
	}

	void _PostOrder(Node *proot)
	{
		if (proot)
		{
			_PostOrder(proot->_pLeft);
			_PostOrder(proot->_pRight);
			cout << proot->_value << "->";
		}
	}

	void _LeverOrder(Node *proot, queue<Node*>& q)
	{
		while (!q.empty())
		{
			Node* temp = q.front();
			cout << temp->_value << "->";
			q.pop();
			if (temp->_pLeft)
				q.push(temp->_pLeft);
			if (temp->_pRight)
				q.push(temp->_pRight);
		}
		cout << "end" << endl;
	}

	Node* _GetParent(Node* proot, Node* x)
	{
		if (proot->_pLeft == x || proot->_pRight == x)
			return proot;
		if (proot->_pLeft == NULL || proot->_pRight == NULL)
			return NULL;
		Node* Temp = _GetParent(proot->_pLeft, x);
		if (Temp == NULL)
		{
			Temp = _GetParent(proot->_pRight, x);
		}
		return Temp;
	}

	Node* _FindNode(Node* proot, const T& value)
	{
		if (proot == NULL || proot->_value == value)
			return proot;
		Node* Temp = _FindNode(proot->_pLeft, value);
		if (Temp == NULL)
		{
			Temp = _FindNode(proot->_pRight, value);
		}
		return Temp;
	}

	size_t _Hight(Node* proot)
	{
		if (proot == NULL)
			return 0;
		size_t LeftHight = 1 + _Hight(proot->_pLeft);
		size_t RightHight = 1 + _Hight(proot->_pRight);
		return (LeftHight>RightHight) ? LeftHight : RightHight;
	}

	size_t _GetLeefNode(Node* proot)
	{
		if (proot == NULL)
			return 0;
		if (proot->_pLeft == NULL && proot->_pRight == NULL)
			return 1;
		size_t LeftLeefNode = _GetLeefNode(proot->_pLeft);
		size_t RightLeefNode = _GetLeefNode(proot->_pRight);
		return (LeftLeefNode + RightLeefNode);
	}

	size_t _GetLevelNode(Node* proot, size_t k)
	{
		size_t h = _Hight(proot);
		if (k == 1)
			return 1;
		if (proot == NULL || k> h)
			return 0;

		size_t LeftLevelNode = _GetLevelNode(proot->_pLeft, k - 1);
		size_t RightLevelNode = _GetLevelNode(proot->_pRight, k - 1);
		return (LeftLevelNode + RightLevelNode);

	}

	void _PreOrder_Nor(Node* proot)
	{
		cout << "ǰ��";
		stack<Node*> st;
		st.push(proot);
		while (!st.empty())
		{
			Node* temp = st.top();
			cout << temp->_value << "->";
			st.pop();
			if (temp->_pRight)
				st.push(temp->_pRight);
			if (temp->_pLeft)
				st.push(temp->_pLeft);
		}
		cout << "end" << endl;
	}

	void _InOrder_Nor(Node* proot)
	{
		cout << "����";
		stack<Node*> st;
		Node* temp = proot;
		while (temp || !st.empty())
		{
			while (temp)
			{
				st.push(temp);
				temp = temp->_pLeft;
			}
			Node* Top = st.top();
			st.pop();
			cout << Top->_value << "->";
			temp = Top->_pRight;
		}
		cout << "end" << endl;
	}

	void _PostOrder_Nor(Node* proot)
	{
		cout << "����";
		stack<Node*> st;
		Node* pCur = proot;
		Node* pPre = NULL;

		while (pCur || !st.empty())
		{
			while (pCur)
			{
				st.push(pCur);
				pCur = pCur->_pLeft;
			}

			pCur = st.top();
			if (pCur->_pRight == NULL || pCur->_pRight == pPre)
			{
				cout << pCur->_value << "->";
				st.pop();
				pPre = pCur;
				pCur = NULL;
			}
			else
				pCur = pCur->_pRight;
		}

		cout << "end" << endl;
	}

	void _GetBinaryMirror(Node* &proot)
	{
		if (proot == NULL)
			return;
		if (proot->_pLeft || proot->_pRight)
			swap(proot->_pLeft, proot->_pRight);
		_GetBinaryMirror(proot->_pLeft);
		_GetBinaryMirror(proot->_pRight);
	}

	void _GetBinaryMirror_Nor(Node* &proot)
	{
		queue<Node*> q;
		q.push(proot);
		while (!q.empty())
		{
			Node* pCur = q.front();
			q.pop();
			std::swap(pCur->_pLeft, pCur->_pRight);
			if (pCur->_pLetf)
				q.push(pCur->_pLetf);
			if (pCur->_pRight)
				q.push(pCur->_pRight);
		}
	}


private:
	Node *_pRoot;
};

