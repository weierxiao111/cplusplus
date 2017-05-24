#include <iostream>
#include <string.h>
using namespace std;
//class String 
//{
//public :
//      String (const char* str = "")
//		  : _refcount (new int [1])
//	  {
//         if ( NULL == str)
//		 {
//			 _str = new char [1];
//			 _str = '\0';
//		 }
//		 else 
//		 {
//			 _str  = new char [strlen (str)+1];
//			 strcpy (_str, str);
//		    (*_refcount) = 1;
//		}
//	  }
//
//	  String (const String&s)
//		  :_str(s._str)
//		  ,_refcount(s._refcount)
//	  {
//		  (*_refcount) ++;
//	  }
//        
//	  String& operator = (const String& s )
//	  {
//
//		  if (this != &s)
//		  {
//	         String temp(*this);
//		     _str = s._str;
//		     _refcount = s._refcount;
//		     (*_refcount) ++;
//			 if( -- (*temp._refcount) == 0)
//			 {
//			 delete [] temp._str;
//			 delete [] temp._refcount;
//			 }
//			 (*_refcount ) ++;
//		  }
//		  return (*this);
//	  }
//
//	  ~String ()
//	  {
//		  if ( --(*_refcount) == 0 && _str!= NULL)
//		  {
//			  delete [] _str;
//			  delete []_refcount;
//			  _str = NULL;
//			  cout<<"~String ()"<< endl;
//		  }
//	  }
//private:
//	  char *_str;
//      int*  _refcount;
//};
//
//int main()
//{
//	String s1("hello"); 
//	String s2(s1);
//	String s3;
//	s3 = s1;
//
//	return 0;
//}

// Ð´Êµ¿½±´
//
class String 
{
public :
	String (const char* str = "")
		:_str(new char [strlen(str)+5])
	{
		if (NULL == str)
		{
			_str = new char(5);
			*(int*)_str= 1;
			_str += 4;
			_str = '\0';
		}
		else 
		{
		     *(int*)_str= 1;
		     _str += 4;
			 strcpy (_str, str);
		}		 
	}

	String (const String& s)
		:_str(s._str)
	{
		(*(int*)(_str-4)) ++;
	}

	String operator = (const String& s)
	{
		if (_str != s._str)
		{
            Release();
			_str = s._str;
			(*(int*)(_str-4)) ++;
		}
		return (*this);
	}


	~String ()
	{
		if ( -- (*(int*)(_str-4)) == 0 )
		{
			delete [] (_str-4 );
			_str = NULL;
			cout <<"~String ()"<<endl;
		}
	}


	void Release ()
	{
		if ( --(*(int*)(_str-4)) == 0)
		{
			delete [](_str-4);
		}
	}

	friend ostream& operator<<(ostream& cout, String& s)
	{
		cout << s._str << endl;
		return cout;
	}

	char operator[] (const int index)
	{
		return _str[index];
	}

private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2 ;
	String s3(s2);
	s2 = s1;
	cout<<s2[1]<<endl;

	return 0;
}