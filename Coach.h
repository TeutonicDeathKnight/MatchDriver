#pragma once
#include "Person.h"

//class to store data and functions related to the data
//	for a coach to assign to a match
class Coach : public Person
{
	friend std::ostream operator<< (std::ostream&, Coach);
	//overload << operator to provide easy use of outputting class data

public:
	void setTitle(std::string t);
	//sets data member title to passed in value

	std::string getTitle() const;
	//returns data member title value

	void setHiredDate(Date* date);
	//sets data member hiredDate value to passed in date object values

	std::string getHiredDate() const;
	//returns string value for data member hiredDate value

	Coach();
	//zero argument constructor / default constructor

	Coach(std::string t, int hd, int hm, int hy
		, std::string l, std::string f, int bd, int bm, int by, std::string j);
	//multiple argument constructor
	//	initializes member variables title and hiredDate to first four passed in values
	//	initializes inhereted data members from person to last 6 values

	~Coach();
	//destructor

private:
	std::string title;
	//stores value for coach's title

	Date hiredDate;
	//Date object that stores value for coach's hired date
};