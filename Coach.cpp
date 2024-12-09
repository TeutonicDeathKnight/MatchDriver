#include <iostream>
#include <iomanip>
#include <string>
#include "FuncUtils.h"
#include "Person.h"
#include "Coach.h"

using namespace std;

//<< operator overload function
ostream& operator<< (std::ostream& output, Coach c)
{
	output << right << setw(25) << "Name - Title: "
		<< c.getLastName() << ", " << c.getFirstName() << " - " << c.getTitle() << "\n"
		<< setw(25) << "Jersey #: " << c.getJerseyNumber() << "\n"
		<< setw(25) << "Birth Date: " << c.getBirthDate() << "\n"
		<< setw(25) << "Years Coached:" << c.getYearsCoached() << "\n"
		<< setw(25) << "Hire Date: " << c.getHiredDate() << "\n"
		<< setw(25) << "Annual Salary: " << c.getAnnualSalary() << "\n\n";

	return output;
}

//setTitle()
void Coach::setTitle(std::string t) { title = t; }

//getTitle()
string Coach::getTitle() const { return title; }

//setHiredDate()
void Coach::setHiredDate(int day, int month, int year)
{
	hiredDate = Date(day, month, year);
}

//getHiredDate()
string Coach::getHiredDate() const
{
	FuncUtils util = FuncUtils();

	return util.formatDate(hiredDate.getDay(), hiredDate.getMonth(), hiredDate.getYear());
}

//setAnnualSalary()
void Coach::setAnnualSalary(double salary) { annualSalary = salary; }

//getAnnualSalary()
double Coach::getAnnualSalary() const { return annualSalary; }

//setYearsCoached()
void Coach::setYearsCoached(int years) { yearsCoached = years; }

//getYearsCoached()
int Coach::getYearsCoached() const { return yearsCoached; }

//default constructor
Coach::Coach()
	: Person()
{
	title = "";
	hiredDate = Date();
	annualSalary = 0.0;
	yearsCoached = 0;
}

//multi argument constructor
Coach::Coach(std::string t, int hd, int hm, int hy, double s, int y
		, std::string l, std::string f, int bd, int bm, int by, std::string j)
	: Person(l, f, bd, bm, by, j)
{
	setTitle(t);
	setHiredDate(hd, hm, hy);
	setAnnualSalary(s);
	setYearsCoached(y);
}

//destructor
Coach::~Coach() {}