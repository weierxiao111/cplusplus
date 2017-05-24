
String ::String(const char* str  )
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




