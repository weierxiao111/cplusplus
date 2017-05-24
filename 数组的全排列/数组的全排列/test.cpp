#include <iostream>
void PrintArr(int *arr, int sz)
{
	for (int i = 0; i< sz; ++i)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void arrangement(int *arr, int sz, int n)
{
	if (n == sz)
	{
		PrintArr(arr,sz);
		return ;
	}

	for (int idx = n; idx < sz; ++idx)
	{
		std::swap(arr[n],arr[idx]);
		arrangement(arr, sz, n+1);
		std::swap(arr[n],arr[idx]);
	}
}

int main()
{
	int arr[] = {1,2,3,4,5};
	arrangement(arr,5,0);
	return 0;
}