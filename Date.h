#pragma once


//Date.h
//	Purpose: To provide the ability to work with dates in C++.

#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>

class Date
{
	/*
	* This is an overload of the << operator so this  class
	* can output a formatted date.
	*
	* Example:
	* Date myDate; // define a Date variable
	*
	* myDate(1,1,1900); // load Date variable with data
	*
	* // displays the formatted date value in the Date variable
	* cout << myDate; // outputs 1/1/1900
	*
	* The function is a non-member of the class. Using the
	* friend declaration allows the function to have access
	* to private and protected members of the class.
	*/
	friend std::ostream & operator<<(std::ostream&, Date);

public:
	Date();
	//zero argument constructor / default constructor

	Date(int, int, int);
	//three argument constructor
	//	initializes all date member variables to passed in values
	//	default values of 0 if no value passed into constructor

	~Date();
	//class destructor
	
	void setDate(int, int, int);
	//date object setter
	//	sets all date member vairables to passed in values

  private:
	int day;
	//stores value for day

	int month;
	//stores value for month

	int year;
	//stores value for year
};
