#pragma once
#include "¶þ²æÊ÷.hpp"

void PrintPath(TreeNode<int> *proot, int K, int cursum, vector<int> &v);
void FindKPath(TreeNode<int> *proot, int K)
{
	if (NULL == proot)
		return;
	vector<int> v;
	int cursum = 0;
	PrintPath(proot, K, cursum, v);
}

void PrintPath(TreeNode<int> *proot, int K, int cursum, vector<int> &v)
{
	if (NULL == proot )
		return;

	cursum += proot->_value;
	v.push_back(proot->_value);

	if (NULL == proot->_pLeft && NULL == proot->_pRight && cursum == K)
	{
		vector<int> ::iterator it = v.begin();
		for (; it != v.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
	PrintPath(proot->_pLeft, K, cursum , v);
	PrintPath(proot->_pRight, K, cursum, v);
	v.pop_back();
}
