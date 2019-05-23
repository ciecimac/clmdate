// clmdate.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyDate
{
private:
	int year;
	int month;
	int day;
	int check();

public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
	void addDate(CMyDate od);
};
void CMyDate::addDate(CMyDate od)
{
	year = year + od.year;
	month = month + od.month;
	day = day + od.day;
	check();
}
CMyDate::CMyDate()
{
	year = 2019;
	month = 1;
	day = 1;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();

}
int CMyDate::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
	return 0;

}
void CMyDate::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int CMyDate::check()
{
	int flatYearDays[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };
	int temp=1;
	while (temp == 1&&month!=0&&day!=0)
	{
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month ] < day)
			{
				day = day - leapYearDays[month ];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		else
		{
			if (flatYearDays[month ] < day )
			{
				day = day - flatYearDays[month ];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		if (month > 12)
		{
			year++;
			month = month - 12;
			temp = 1;
		}
	}

return 0;
}
int CMyDate::getYear()
{
	return year;
}
int CMyDate::getMonth()
{
	return month;
}
int CMyDate::getDay()
{
	return day;
}
void CMyDate::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}

}
int main()
{
	CMyDate od1(2020,2,29),od2(1,2,20);
	int i;
	int count = 1;
	od1.addDate(od2);
	od1.displayDate();
	od2.displayDate();
	
	return 0;
}

