#include <stdio.h>
#include <string.h>
int main()
{

	int num = 5;
	const int *a = &num; //¶¥²ãconst
   int  * const b =a;

	return 0;
}