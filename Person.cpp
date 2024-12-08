#include <string>
#include "Date.h"
#include "Person.h"

using namespace std;

void Person::setLastName(string name) { lastName = name; }

string Person::getLastName() const { return lastName; }

void Person::setFirstName(string name) { firstName = name; }

string Person::getFirstName() const { return firstName; }

void Person::setBirthDate(Date* date)
{
	birthDate.setDate(date->getDay(), date->getMonth(), date->getYear());
}

string Person::getBirthDate() const
{
	string output = "";

	//if birth month is less than 10, add a leading zero to adhere to mm format
	if (birthDate.getMonth() < 10 && birthDate.getMonth() > 0)
		output += '0' + birthDate.getMonth();
	else
		output += birthDate.getMonth();

	output += '/';

	//if birth month is lesss than 10, add a leading zero to adhere to the dd format
	if (birthDate.getDay() < 10 && birthDate.getDay() > 0)
		output += '0' + birthDate.getDay();
	else
		output += birthDate.getDay();

	output += '/' + birthDate.getYear();

	return output;
}

void Person::setJerseyNumber(string jersey) { jerseyNumber = jersey; }

string Person::getJerseyNumber() { return jerseyNumber; }

Person::Person()
{
	lastName = "";
	firstName = "";
	birthDate = Date();
	jerseyNumber = "";
}

Person::Person(string last, string first, int day, int month, int year, string jersey)
{
	setLastName(last);
	setFirstName(first);
	setBirthDate(&Date(day, month, year));
	setJerseyNumber(jersey);
}

Person::~Person()
{
	lastName = "";
	firstName = "";
	delete &birthDate;
	jerseyNumber = "";
}