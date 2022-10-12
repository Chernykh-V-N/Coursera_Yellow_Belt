#pragma once

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Date
{
public:
	Date() = default;

	Date(const int& year_, const int& month_, const int day_);

	int GetYear() const;

	int GetMonth() const;

	int GetDay() const;



	Date& operator=(const Date& date_);

private:
	 int year;
	 int month;
	 int day;
};

bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& os, const Date& date_);

Date ParseDate(istream& is);