//Date.cpp
//  Purpose: To provide the ability to work with dates in C++.

#include "Date.h"

std::ostream& operator<<(std::ostream& output, Date d)
/*
* This function is used to give the user the date
* in a formatted structure that can be used in
 * a cout statement.
 * See the Date.h file for an example.
 */
{
    output << d.month << "/" << d.day << "/" << d.year;
    return output;
}

Date::Date()
{
    setDate(1, 1, 1900);
}

Date::Date(int d = 0, int m = 0, int yyyy = 0)
{
    setDate(d, m, yyyy);
}

Date::~Date() {}

void Date::setDate(int d, int m, int yyyy)
{
    day = d;
    month = m;
    year = yyyy;
}
