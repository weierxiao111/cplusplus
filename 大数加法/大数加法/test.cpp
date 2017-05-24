#include <stdio.h>
#include <string.h>
char* MaxReduce(char* num1, char* num2)
char* MaxAdd(char* num1, char* num2)
{
	assert(num1 && num2);
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	if (judge(num1) == judge(num2) )
	{
		if (judge(num1) == 1)
		{
            for (int i = len-1; i > = 0; i -- )
			{
                if (NULL == num1[i] || NULL == num2[i])
					break;
				int count = num1[i] + num2[i] - 47;
				if (count >= '0' )
					
					
			}
		}
		if (judge(num1) == -1)
	}



}

int judge (char* number)
{
	assert(number);
	if (number[0] - '-')
		return -1;
	else if (number[0]>= 49 && number[0] <= 57)
		return 1;
	else 
		return 0;
}

int main()
{

	return 0;
}