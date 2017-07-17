#pragma once
#include <assert.h>
int maxAnd(int *arr, int sz)
{
	assert(arr);
	int maxarr = 0;
	int thisarr = 0;
	for (int i = 0; i < sz; ++i)
	{
		thisarr += arr[i];

		if (thisarr < 0)
			thisarr = 0;
		else if (thisarr > maxarr)
			maxarr = thisarr;
	}

	return maxarr;
}