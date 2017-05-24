#include <iostream>
using namespace std;

enum Status{invalid = 0, valid};
int g_status = valid;
long long StrToInt(const char* str, bool symbol);
int MyAtoi(const char* str)
{
	g_status = invalid;
	long long num = 0;
	if (NULL != str || (*str) != '\0')
	{
		bool symbol = true;
		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			symbol = false;
			str++;
		}

		if (*str != '\0')
		{
			num = StrToInt(str, symbol);
		}

	}

	return num;
}

long long StrToInt(const char* str, bool symbol)
{
	long long num = 0;
	int flag = symbol? 1: -1;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			num = (num*10)+(flag*(*str - '0'));

			if ((symbol && num> 0x7FFFFFFF) ||
				(!symbol && num< (signed)0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*str == '\0')
	{
		g_status = valid;
		return num;
	}

}

int main()
{
	char* num = "-2147483648";
	int number = MyAtoi(num);
	cout<<number<<endl;
	cout<<g_status<<endl;
	return 0;
}