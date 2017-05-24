#include <iostream>
#include "date.h"
using namespace std;


bool Date::_isleap( int year)
	{
		if ((year%400 ==0) || ((year%4 ==0) && (year%100 != 0 )))
			return true; // 是闰年
		return  false;  // 不是闰年
	}

int Date::getday(int year, int month)
{
	int day[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (  month == 2 && _isleap(year) )
		day[month] = 29;
	return day[month];
		
}


Date::Date(int year, int month, int day)
:_year(year),
_month (month),
_day (day)
	{  
		if ((year < 0) || month <1 || month > 12 || day< 1 || day > getday (year, month))
		{
			cout << "day is not correct !" <<endl;
		
			_year = 2017;
		    _month = 2; 
		    _day = 21;
		}

	}

Date::Date(const Date &d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date:: operator = (const Date& d)
{
	if (this != &d )

	_year = d._year;
	_month = d._month;
	_day = d._day;

	return (*this);
}

Date Date::operator +(int day)
{
   Date temp(*this);
   if (day <0)
   {
	   temp._day += day;
	   while (temp._day < 1)
	   {
		   temp._month --;
		   if (temp._month < 1)
		   {
			   temp._month = 12;
			   temp._year --;
		   }

		   temp._day += getday( temp._year, temp._month);
	   }
   }
   if (day >0)
   {
	   int ret =0;
	   temp._day += day;
	   	   while (temp._day > (ret= getday(temp._year, temp._month)))
	   {
		   temp._day -= ret;
		   temp._month ++;
		   if (temp._month >12 )
		   {
			   temp._year++;
			   temp._month = 1;
		   }
	   }
   }
   return temp;
}

Date Date::operator -(int day)
{  
       return (*this) +(0-day) ; 
	
}

// 前置++
Date&  Date ::operator++()
{
	(*this) =(*this) + 1; 
	return (*this);
}

	// 后置++
Date   Date ::operator++(int)
{
	Date temp(*this);
	(*this)  = (*this) + 1;
	return temp;
}
	
	// 前置--
Date&  Date ::operator--()
{
	(*this) = (*this) -1; 
	return (*this);
}

	// 后置--
Date   Date ::operator--(int)
{
	Date temp(*this);
	(*this)  = (*this) - 1;
	return temp;
}

bool  Date::operator>(const Date& date)  
{  
    if (_year > date._year || (_year == date._year && _month > date._month) || (_year == date._year && _month == date._month && _day > date._day))  
    {  
        return true;  
    }  
    else  
        return false;  
}  
  
bool  Date::operator<(const Date& date)  
{  
    if (_year < date._year || (_year == date._year && _month < date._month) || (_year == date._year && _month == date._month && _day < date._day))  
    {  
        return true;  
    }  
    else  
        return false;  
}  
  
bool  Date::operator==(const Date& date)  
{  
    return _year == date._year && _month == date._month && _day == date._day;  
}  
  
bool  Date::operator!=(const Date& date)  
{  
    return _year != date._year || _month != date._month || _day != date._day;  
}  
  
bool  Date::operator>=(const Date& date)  
{  
    if (*this < date)  
        return false;  
    else  
        return true;  
}  
  
bool  Date::operator<=(const Date& date)  
{  
    if (*this > date)  
        return false;  
    else  
        return true;  
}  

Date ::~Date()
{
    cout <<"数据已经清理"<<endl;
}
ostream& operator << (ostream & cout,const Date &d)
{
	cout << d._year<<"年"<<d._month<< "月" << d._day<< "日"<<endl;
	return cout;
}

 