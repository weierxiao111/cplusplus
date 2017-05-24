#include <iostream>
#include <string.h>
//using namespace std;
////  深拷贝简单版本
//class String
//{
//public:
//	String(const char* str = "" )
//	{
//		if (NULL == str)
//		{
//			_str = new char [1];
//			_str = '\0';
//         }
//		else {
//			_str = new char[strlen(str)+1] ;
//			strcpy(_str,str);
//		}
//	}
//
//	String (const String& s)
//		:_str(new char[strlen(s._str)+1] )
//	{
//		if (this != &s)
//		{
//			strcpy (_str, s._str) ;
//		}
//	}
//
//	String& operator = (const String &s)
//	{
//		String temp(s);
//		return temp;
//	}
//
//	~String ()
//	{
//		if (NULL != _str)
//		{
//			delete [] _str;
//			cout << "~String()"<<endl;
//          _str = NULL;
//		}
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	String   s1("hello");
//	String   s2(s1);
//	String   s3 = s1;
//	return 0;
//}

//深拷贝现代版

class String
{
public :
	String(const char* str = "" )
	{
		if (NULL == str)
		{
			_str = new char [1];
			_str = '\0';
         }
		else 
		{
			_str = new char[strlen(str)+1] ;
			strcpy(_str,str);
		}
	}

	String (const String& s)
	:_str(NULL)
	{
		String temp(s._str);
		std::swap (_str , temp._str);
	}

	String& operator = (const String& s)
	{
		String temp(s);
		return temp;
	}

	~String ()
	{
		if (NULL != _str)
		{
			delete [] _str;
			std::cout << "~String()"<<std::endl;
		}
	}


private:
	char *_str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	String s3 = s2;
	return 0;
}