#ifndef __STRING_H_
#define __STRING_H_ 

#include <iostream>

using namespace std;

class String
{
public:
	String (const char*  str = "");
    String (const String& s );
    String& operator =(const String&  s);
private:
	char* _str;
};

#endif  // __STRING_H_