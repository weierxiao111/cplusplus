# include "String.h"

String ::String(const char* str )
:_str(new char[strlen(str) +1])
{
	if (str == NULL)
	{
		_str = new char[1];
		_str = '\0';
	}

    strcpy(_str, str);
}

String ::String (const String& s )
{
	strcpy(_str,s._str);
}

String&  String:: operator =(const String&  s)
{
	strcpy (_str, s._str);
	return (*this);
}
