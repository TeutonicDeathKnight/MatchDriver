#pragma once
#include <string>

class FuncUtils
{
public:
	std::string formatDate(int day, int month, int year) const;
	//return formatted date string as mm/dd/yyyy

	std::string collectStringInput(std::string prompt, std::string errMessage);
	//prompt user for string input and validate string input is correct

	int convertCharNumberToInt(char c);
	//converts character to int value

	std::string validateDateStringInput(std::string input, int& day, int& month, int& year);
	//validate string input matches correct formatting for date mm/dd/yyyy
	//	mm must be within 01-12
	//	dd must be within 1-31
	//	yyyy must be 1900 or greater up to current year

	bool validateNotEmptyString(std::string strToTest);
	//validate string input is not empty or blank characters
	
	void clearInputStream();
	//clear input stream
};