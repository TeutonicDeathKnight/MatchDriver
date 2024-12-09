//Date.cpp
//  Purpose: To provide the ability to work with dates in C++.

#include "FuncUtils.h"
#include "Date.h"

std::ostream& operator<<(std::ostream& output, Date d)
{
    FuncUtils util;

    output << util.formatDate(d.day, d.month, d.year);

    return output;
}

Date::Date() { setDate(1, 1, 1900); }

Date::Date(int d = 0, int m = 0, int yyyy = 0) { setDate(d, m, yyyy); }

Date::~Date() {}

int Date::getDay() const { return day; }

int Date::getMonth() const { return month; }

int Date::getYear() const { return year; }

void Date::setDate(int d, int m, int yyyy)
{
    day = d;
    month = m;
    year = yyyy;
}
