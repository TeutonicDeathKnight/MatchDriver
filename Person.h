#pragma once
#include "Date.h"

//class to store data and functions related to the data for a person
class Person
{
public:
	void setLastName(std::string name);
	//sets data member lastName value to passed in value

	std::string getLastName() const;
	//returns data member lastName value

	void setFirstName(std::string name);
	//sets data member firstName value to passed in value

	std::string getFirstName() const;
	//returns data member firstName value

	void setBirthDate(int day, int month, int year);
	//sets data member birthDate value to passed in date object values

	std::string getBirthDate() const;
	//returns string related to values stored in data member birthDate

	void setJerseyNumber(std::string jersey);
	//sets data member jerseyNumber value

	std::string getJerseyNumber();
	//returns data member jerseyNumber value

	Person();
	//zero argument constructor / default constructor

	Person(std::string last, std::string first
		, int day, int month, int year
		, std::string jersey);
	//multiple argument constructor
	//	initializes member variables lastName, firstName, birthDate, and jerseyNumber
	//	to passed in values

	~Person();
	//destructor

private:
	std::string lastName;
	//stores value for person's last name

	std::string firstName;
	//stores value for person's first name

	Date birthDate;
	//Date object that stores value for person's birth date

	std::string jerseyNumber;
	//stores value for person's jersey number
};