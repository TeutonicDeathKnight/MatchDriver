#include <iostream>
#include <string>
#include "FuncUtils.h"

//formatDate()
std::string FuncUtils::formatDate(int day, int month, int year) const
{
	std::string output = "";

	//if birth month is less than 10, add a leading zero to adhere to mm format
	if (month < 10 && month > 0)
		output += '0' + month;
	else
		output += month;

	output += '/';

	//if birth day is lesss than 10, add a leading zero to adhere to the dd format
	if (day < 10 && day > 0)
		output += '0' + day;
	else
		output += day;

	output += '/' + year;

	return output;
}

//collectStringInput()
std::string FuncUtils::collectStringInput(std::string prompt, std::string errMessage)
{
	bool validInputFlag = false;
	std::string input;

	//while input is not valid,
	//	prompt and reprompt user for valid text input
	do
	{
		std::cout << prompt;

		std::getline(std::cin, input);

		if (validateNotEmptyString(input) == false)
			std::cout << errMessage;
		else
			validInputFlag = true;

	} while (validInputFlag == false);

	return input;
}

int FuncUtils::convertCharNumberToInt(char c)
{
	int output;

	switch (c)
	{
	case '1':
		output = 1;
		break;
	case '2':
		output = 2;
		break;
	case '3':
		output = 3;
		break;
	case '4':
		output = 4;
		break;
	case '5':
		output = 5;
		break;
	case '6':
		output = 6;
		break;
	case '7':
		output = 7;
		break;
	case '8':
		output = 8;
		break;
	case '9':
		output = 9;
		break;
	case '0':
		output = 0;
		break;
	default:
		output = -1;
	}

	return output;
}

std::string FuncUtils::validateDateStringInput(std::string input, int& day, int& month, int& year)
{	std::string errOutput = "";

	for (int i = 0; i < input.length(); i++)
	{
		if (i == 0)
		{
			if (input[i] == '0')
				month = 0;
			else if (input[i] == '1')
				month = 10;
			else
				errOutput +=
				"\nMonth input was too large and must be between 01 and 12 inclusive";
		}
		else if (i == 1)
		{
			if (input[i] == '0' && month == 0)
				errOutput +=
				"\nMonth input was \"00\" and must be between 01 and 12 inclusive.";
			else
				month += convertCharNumberToInt(input[i]);
		}
		else if (i == 3)
		{
			if (input[i] == '0')
				day = 0;
			else if (input[i] == '1')
				day = 10;
			else if (input[i] == '2')
				day = 20;
			else if (input[i] == '3')
				day = 30;
			else
				errOutput +=
				"\nDay input was too large and must be between 01 and 31 inclusive.";
		}
		else if (i == 4)
		{
			if (input[i] == '0' && day == 0)
				errOutput += "\nDay input was \"00\" and must be between 01 and 31 inclusive.";
			else
				day += convertCharNumberToInt(input[i]);
		}
		else if (i == 6)
		{
			year = convertCharNumberToInt(input[i]) * 1000;
		}
		else if (i == 7)
		{
			year += convertCharNumberToInt(input[i]) * 100;
		}
		else if (input[i] == 8)
			year += convertCharNumberToInt(input[i]) * 10;
		else if (input[i] == 9)
			year += convertCharNumberToInt(input[i]);
	}

	if (year == 0)
		errOutput += "\nYear input was \"0000\" and must be greater than that.";

	if (errOutput != "")
		errOutput += "\nDate input must be in the format of mm/dd/yyyy.\n\n";

	return errOutput;
}



//validateNotEmptyString()
bool FuncUtils::validateNotEmptyString(std::string strToTest)
{
	bool containsNonWhitespaceChars = false;
	std::string str = strToTest;

	//loop through strToTest
	for (int position = 0; position < str.length(); position++)
	{
		char evalChar = str[position];

		//if current character is one of the 6 whitespace characters
		// replace with the null character
		if (evalChar == 9
			|| evalChar == 10
			|| evalChar == 11
			|| evalChar == 12
			|| evalChar == 13
			|| evalChar == 32)
		{
			str[position] = '\0';
		}
	}

	//loop through string and if a non whitespace character is found
	// set containsNonWhitespaceChars to true and break out of loop
	for (int position = 0; position < str.length(); position++)
		if (str[position] != '\0')
		{
			containsNonWhitespaceChars = true;
			break;
		}

	//if input is only whitespace characters, output error message
	/*if (containsNonWhitespaceChars == false)
	{
		std::cout << "\nInput cannot be blank or only whitespace characters.\n";
		clearInputStream();
	}*/

	return containsNonWhitespaceChars;
}

//clearInputStream()
void FuncUtils::clearInputStream()
{
	//clear 
	std::cin.clear();
	//ignore rest of line determining max length of line
	//	until the newline character appears
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}