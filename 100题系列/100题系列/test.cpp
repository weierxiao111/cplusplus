#include <iostream>
#include "ÌâÄ¿ËÄ.hpp""

using namespace std;

/*void Test3()
{
	int arr[] = { 1, -2, 3, 10, -4,7 ,2, -5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	cout << maxAnd(arr, sz) << endl;
}*/

void Test4()
{
	int arr[] = { 10, 7, 3, 0, 0, 2, 0, 0 ,5,4,0,0,1 };
	BinaryTree<int> tree(arr, sizeof(arr) / sizeof(arr[0]), 0);
	FindKPath(tree.GetRoot(), 19);
}

int main()
{
	Test4();
	return 0;
}