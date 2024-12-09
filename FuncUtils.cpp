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
				switch (input[i])
				{
				case '1':
					month += 1;
					break;
				case '2':
					month += 2;
					break;
				case '3':
					month += 3;
					break;
				case '4':
					month += 4;
					break;
				case '5':
					month += 5;
					break;
				case '6':
					month += 6;
					break;
				case '7':
					month += 7;
					break;
				case '8':
					month += 8;
					break;
				case '9':
					month += 9;
					break;
				}
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
				switch (input[i])
				{
				case '1':
					day += 1;
					break;
				case '2':
					day += 2;
					break;
				case '3':
					day += 3;
					break;
				case '4':
					day += 4;
					break;
				case '5':
					day += 5;
					break;
				case '6':
					day += 6;
					break;
				case '7':
					day += 7;
					break;
				case '8':
					day += 8;
					break;
				case '9':
					day += 9;
					break;
				}
		}
		else if (i == 6)
		{
			switch (input[i])
			{
			case '1':
				day = 1000;
				break;
			case '2':
				day = 2000;
				break;
			case '3':
				day = 3000;
				break;
			case '4':
				day = 4000;
				break;
			case '5':
				day = 5000;
				break;
			case '6':
				day = 6000;
				break;
			case '7':
				day = 7000;
				break;
			case '8':
				day = 8000;
				break;
			case '9':
				day = 9000;
				break;
			}
		}
		else if (i == 7)
		{
			switch (input[i])
			{
			case '1':
				day += 100;
				break;
			case '2':
				day += 200;
				break;
			case '3':
				day += 300;
				break;
			case '4':
				day += 400;
				break;
			case '5':
				day += 500;
				break;
			case '6':
				day += 600;
				break;
			case '7':
				day += 700;
				break;
			case '8':
				day += 800;
				break;
			case '9':
				day += 900;
				break;
			}
		}
		else if (input[i] == 8)
			switch (input[i])
			{
			case '1':
				day += 10;
				break;
			case '2':
				day += 20;
				break;
			case '3':
				day += 30;
				break;
			case '4':
				day += 40;
				break;
			case '5':
				day += 50;
				break;
			case '6':
				day += 60;
				break;
			case '7':
				day += 70;
				break;
			case '8':
				day += 80;
				break;
			case '9':
				day += 90;
				break;
			}
		else if (input[i] == 9)
			switch (input[i])
			{
			case '1':
				day += 1;
				break;
			case '2':
				day += 2;
				break;
			case '3':
				day += 3;
				break;
			case '4':
				day += 4;
				break;
			case '5':
				day += 5;
				break;
			case '6':
				day += 6;
				break;
			case '7':
				day += 7;
				break;
			case '8':
				day += 8;
				break;
			case '9':
				day += 9;
				break;
			}
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