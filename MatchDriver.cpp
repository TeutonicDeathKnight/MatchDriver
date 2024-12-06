//MatchDriver.cpp -- Create a list of starting players and positions for a volleyball match
//CSIS 212-<D02_202440>

//Sources
// 
// 
// 
//collectStringInput(), validateNotEmptyString(), and clearInputStream()
//	logic taken from my lab 6 submission

//include and using statements
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function prototypes

string collectStringInput(string prompt, string errMessage);
bool validateNotEmptyString(string strToTest);
void clearInputStream();

//main()
int main()
{
	cout << "Zachary Seeley -- Lab 7 - Inheritance / Operator Overloading\n\n\n";

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

string collectStringInput(string prompt, string errMessage)
{
	bool inputFlag = false;
	string input;

	//while input is not valid,
	//	prompt and reprompt user for valid text input
	do
	{
		cout << prompt;

		getline(cin, input);

		if (validateNotEmptyString(input) == false)
			cout << errMessage;
		else
			inputFlag = true;

	} while (inputFlag == false);

	return input;
}

//validateNotEmptyString()
bool validateNotEmptyString(string strToTest)
{
	bool containsNonWhitespaceChars = false;
	string str = strToTest;

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
	if (containsNonWhitespaceChars == false)
	{
		cout << endl << "Input cannot be blank or only whitespace characters." << endl
			<< "Press enter to continue." << endl;
	}

	return containsNonWhitespaceChars;
}

//clearInputStream()
void clearInputStream()
{
	//clear 
	cin.clear();
	//ignore rest of line determining max length of line
	//	until the newline character appears
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}