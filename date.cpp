#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

#include "date.h"

Date::Date(const int& year_, const int& month_, const int day_)
	: year(year_), month(month_), day(day_)
{}

int Date::GetYear() const
{
	return year;
}
int Date::GetMonth() const
{
	return month;
}
int Date::GetDay() const
{
	return day;
}

Date& Date::operator=(const Date& date_)
{
	this->year = date_.GetYear();
	this->month = date_.GetMonth();
	this->day = date_.GetDay();

	return *this;
}

/*
bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear() || lhs.GetMonth() != rhs.GetMonth() || lhs.GetDay() != rhs.GetDay())
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

bool operator==(const Date& lhs, const Date& rhs)
{
	const long log1 = lhs.GetYear() * 372 + lhs.GetMonth() * 31 + lhs.GetDay();
	const long log2 = rhs.GetYear() * 372 + rhs.GetMonth() * 31 + rhs.GetDay();

	return log1 == log2;
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	const long log1 = lhs.GetYear() * 372 + lhs.GetMonth() * 31 + lhs.GetDay();
	const long log2 = rhs.GetYear() * 372 + rhs.GetMonth() * 31 + rhs.GetDay();

	return log1 != log2;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear())
	{
		return lhs.GetYear() < rhs.GetYear();
	}
	if (lhs.GetMonth() != rhs.GetMonth())
	{
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetDay() < rhs.GetDay();
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear())
	{
		return lhs.GetYear() < rhs.GetYear();
	}
	if (lhs.GetMonth() != rhs.GetMonth())
	{
		return lhs.GetMonth() < rhs.GetMonth();
	}
	if (lhs.GetDay() != rhs.GetDay())
	{
		return lhs.GetDay() < rhs.GetDay();
	}
	return true;
}

bool operator>(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear())
	{
		return lhs.GetYear() > rhs.GetYear();
	}
	if (lhs.GetMonth() != rhs.GetMonth())
	{
		return lhs.GetMonth() > rhs.GetMonth();
	}
	return lhs.GetDay() > rhs.GetDay();
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() != rhs.GetYear())
	{
		return lhs.GetYear() > rhs.GetYear();
	}
	if (lhs.GetMonth() != rhs.GetMonth())
	{
		return lhs.GetMonth() > rhs.GetMonth();
	}
	if (lhs.GetDay() != rhs.GetDay())
	{
		return lhs.GetDay() > rhs.GetDay();
	}
	return true;
}

ostream& operator<<(ostream& os, const Date& date_)
{
	os << date_.GetYear() << "-" << date_.GetMonth() << "-" << date_.GetDay();
	return os;
}

Date ParseDate(istream& is)
{
	int new_year, new_month, new_day;

	is >> new_year;
	is.ignore(1);

	is >> new_month;
	is.ignore(1);

	is >> new_day;

	return Date(new_year, new_month, new_day);
}
