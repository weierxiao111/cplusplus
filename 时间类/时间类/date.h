#ifndef __DATE_H_
#define __DATE_H_
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator << (ostream & cout, const Date &d);
private :
	int _year;
	int _month;
	int _day;
	int getday(int year, int month);
	bool _isleap(int year);

public :
	Date(int year = 2017, int month = 1, int day = 1);
	Date(const Date&d);
	Date& operator = (const Date &d); 
	Date operator+( int day);
	Date operator-( int day);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);
	bool operator==(const Date& d);
	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);
	
	// 前置--
	Date& operator--();

	// 后置--
	Date operator--(int);

      ~Date();
};



#endif // __DATE_H_