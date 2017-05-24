
#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
	String (const char*  str = "")
	{
	     if (str == NULL)
	     {
		    _str = new char[1];
		    _str = '\0';
	      }
	     else
		{
		 _str=new char [strlen(str) +1];
			strcpy(_str, str);
			}
		}

		String (const String& s )
	{
		strcpy(_str,s._str);
	}
	 String&  String:: operator =(const String&  s)
	{
		if (_str != s._str)
		{
			strcpy(_str,s._str);
		}
		return (*this);
	}

		String::~String()
	{
		if ( _str != NULL)
		{
		   delete[] _str;
			_str = NULL;
		}
	}

	private:
		char* _str;
	};


	int main()
	{
		String s1;
		String s2("hello");
		String s3 (s1);
		return 0;
	}
