#include <string>
#include "Date.h"
#include "FuncUtils.h"
#include "Person.h"

using namespace std;

//setLastName()
void Person::setLastName(string name) { lastName = name; }

//getLastName()
string Person::getLastName() const { return lastName; }

//setFirstName()
void Person::setFirstName(string name) { firstName = name; }

//getFirstName()
string Person::getFirstName() const { return firstName; }

//setBirthDate()
void Person::setBirthDate(int day, int month, int year)
{
	birthDate.setDate(day, month, year);
}

//getBirthDate()
string Person::getBirthDate() const
{
	FuncUtils util = FuncUtils();

	return util.formatDate(birthDate.getDay(), birthDate.getMonth(), birthDate.getYear());
}

//setJerseyNumber()
void Person::setJerseyNumber(string jersey) { jerseyNumber = jersey; }

//getJerseyNumber()
string Person::getJerseyNumber() { return jerseyNumber; }

//Default constructor
Person::Person()
{
	lastName = "";
	firstName = "";
	birthDate = Date();
	jerseyNumber = "";
}

//multi argument constructor
Person::Person(string last, string first, int day, int month, int year, string jersey)
{

	setLastName(last);
	setFirstName(first);
	//set birthDate using Date constructor to ensure date object is created properly
	birthDate = Date(day, month, year);
	setJerseyNumber(jersey);
}

//destructor
Person::~Person() {}