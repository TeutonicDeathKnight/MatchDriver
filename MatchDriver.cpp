//MatchDriver.cpp -- Create a list of starting players and positions for a volleyball match
//CSIS 212-<D02_202440>

//Sources
//Date.h and Date.cpp taken from lab instructions per direction given in instructions
//sort function use in Match.cpp taken from lab instructions
// 
//collectStringInput(), validateNotEmptyString(), and clearInputStream()
//	logic taken from my lab 6 submission

//include and using statements
#include <iostream>
#include <iomanip>
#include <string>
#include "FuncUtils.h"
#include "Match.h"

using namespace std;

//global constant
const string errMessageBase = "\n\nInput is blank and cannot be blank.\n";

//function prototypes
Match collectTeamInfo(FuncUtils& utils);
void menuPrompt(int numPlayers, char& sel);
void selectionTree(char sel, bool& programRunning, Match* m, Coach* c, FuncUtils& utils);
void addCoach(Match* m, Coach* c, FuncUtils& utils);
void listMatchInfo(Match* m);
void collectDateInput(string prompt, FuncUtils& utils
	, string& errMessage, int& day, int& month, int& year);

//main()
int main()
{
	cout << "Zachary Seeley -- Lab 7 - Inheritance / Operator Overloading\n\n\n";

	//create utility object to perform functions from utility library
	FuncUtils utils = FuncUtils();
	bool programRunning = true;

	Match match = collectTeamInfo(utils);
	Coach coach = Coach();

	do
	{
		char selection;

		menuPrompt(match.getMatchPlayersLength(), selection);

		utils.clearInputStream();

		if (selection != 'C' && selection != 'P' && selection != 'L' && selection != 'Q')
			continue;
		else
			cout << "\n\n";

		selectionTree(selection, programRunning, &match, &coach, utils);


	} while (programRunning == true);

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//collectTeamInfo()
Match collectTeamInfo(FuncUtils& utils)
{
	bool validDateInput = false;

	string prompt = "Team Name: ";
	string errMessage = errMessageBase + "You must input the name of the team.\n\n";

	string name = utils.collectStringInput(prompt, errMessage);

	cout << endl;

	prompt = "Match Location: ";
	errMessage = errMessageBase + "You must input the name of the match location.\n\n";

	string location = utils.collectStringInput(prompt, errMessage);

	cout << endl;

	prompt = "Match Opponent: ";
	errMessage = errMessageBase + "You must input the name of the opposing team.\n\n";

	string opponent = utils.collectStringInput(prompt, errMessage);

	cout << endl;

	prompt = "Match Date: ";
	errMessage = errMessageBase + "You must input the date in the correct format.\n"
		"Date must be in the format of mm/dd/yyyy.\n\n";

	int day, month, year;

	collectDateInput(prompt, utils, errMessage, day, month, year);

	cout << endl;

	system("pause");

	return Match(name, location, opponent, day, month, year);
}

//menuPrompt()
void menuPrompt(int numPlayers, char& sel)
{
	cout << "\nMain Menu\n\n"
		<< "C -- Add Coach\n"
		<< "P -- Add Player (" << numPlayers << " of 3 Players entered)\n"
		<< "L -- List Match Information\n"
		<< "Q -- Quit\n\n"
		<< "Selection: ";

	cin >> sel;

	if (cin.fail() || (sel != 'C' && sel != 'P' && sel != 'L' && sel != 'Q'))
		cout << "\n\nSelection was not valid. Selection must be 'C', 'P', 'L', or 'Q'.\n"
			"Selection must be a capital letter, no lower case allowed.\n\n";
}

//selectionTree()
void selectionTree(char sel, bool& programRunning, Match* m, Coach* c, FuncUtils& utils)
{
	if (sel == 'C')
		addCoach(m, c, utils);
	else if (sel == 'P')
		{}//addPlayer(m);
	else if (sel == 'L')
		listMatchInfo(m);
	else if (sel == 'Q')
		programRunning = false;
}

//addCoach()
void addCoach(Match* m, Coach* c, FuncUtils& utils)
{
	if (m->getMatchCoach().getTitle() != "")
	{
		cout << "A coach has already been assigned for this match. Operation canceled.\n";
	}
	else
	{
		string errMessage = errMessageBase + "You must input the first name of the coach.\n\n";

		cout << right << setw(35) << "Enter Coach for Match: " << endl << endl
			<< setw(35) << "First Name: ";

		string first = utils.collectStringInput("", errMessage);

		errMessage = errMessageBase + "You must input the last name of the coach.\n\n";

		cout << setw(35) << "Last Name: ";

		string last = utils.collectStringInput("", errMessage);

		string jersey;

		errMessage = errMessageBase
			+ "You must input the number of the jersey as a two digit number.";

		bool validJersey = false;

		do
		{
			cout << setw(35) << "Jersey Number: ";

			jersey = utils.collectStringInput("", errMessage);

			if (jersey.length() != 2)
			{
				cout << "\nInput was not the correct length. "
					"Input must be a whole numeric value between 00 and 99 inclusive.\n\n";
			}
			else
			{
				int num1 = utils.convertCharNumberToInt(jersey[0]);
				int num2 = utils.convertCharNumberToInt(jersey[1]);

				if (!(num1 >= 0 && num1 <= 9 && num2 >= 0 && num2 <= 9))
				{
					cout << "\nInput was not a numeric value. "
						"Input must be between 00 and 99 inclusive.\n\n";
				}
				else
					validJersey = true;
			}
		} while (validJersey == false);

		errMessage = errMessageBase + "You must input the birth date of the coach.\n\n";

		int bDay, bMonth, bYear;

		collectDateInput("           Birth Date(mm/dd/yyyy): "
			, utils, errMessage, bDay, bMonth, bYear);


		bool validYearsCoached = false;
		int yearsCoached;

		do
		{
			cout << setw(35) << "Years Coached (whole number only): ";

			cin >> yearsCoached;

			if (cin.fail())
				cout << "\nInput must be a single, whole numeric value.\n\n";
			else
				validYearsCoached = true;
			
			utils.clearInputStream();
		} while (validYearsCoached == false);

		errMessage = errMessageBase + "You must input the hired date of the coach.\n\n";

		int hDay, hMonth, hYear;

		collectDateInput("           Hire Date(mm/dd/yyyy): "
			, utils, errMessage, hDay, hMonth, hYear);

		errMessage = errMessageBase + "You must input the title of the coach.\n\n";

		cout << setw(35) << "Title: ";

		string title = utils.collectStringInput("", errMessage);

		bool validAnnualSalary = false;
		double annualSalary;

		cout << setw(35) << "Annual Salary: ";

		do
		{
			cin >> annualSalary;

			if (cin.fail())
				cout << "\nInput must be a numeric value.\n\n";
			else
				validAnnualSalary = true;

			utils.clearInputStream();
		} while (validAnnualSalary == false);

		*c = Coach(title, hDay, hMonth, hYear, annualSalary, yearsCoached
			, last, first, bDay, bMonth, bYear, jersey);

		m->setMatchCoach(c);
	}
	
	cout << '\n';
	system("pause");
}

//listMatchInfo()
void listMatchInfo(Match* m)
{
	string errOutput = "";

	if (m->getMatchCoach().getTitle() == "")
		errOutput += "\nCoach is missing. Operation canceled.";
	if (m->getMatchPlayersLength() < 3)
		errOutput += "\nOne or more of the three required players is missing. "
			"Operation canceled.";

	if (errOutput != "")
	{
		errOutput += "\n\n";
		cout << errOutput;
	}
	else
	{
		cout << "\n\n";

		m->listMatchInformation();
	}

	system("Pause");
}

void collectDateInput(string prompt, FuncUtils& utils
	, string& errMessage, int& day, int& month, int& year)
{
	bool validDateInput = false;
	do
	{
		string date = utils.collectStringInput(prompt, errMessage);

		if (date.length() > 5)
		{
			if (date.length() > 10 || date.length() < 10 || date[2] != '/' || date[5] != '/')
			{
				string output = "";
				if (date.length() > 10 || date.length() < 10)
					output += "\nInput was an incorrect length.";

				if (date[2] != '/' || date[5] != '/')
					output += "\nInput was not in mm/dd/yyyy format "
					"or did not include the '/' character(s) in the correct place(s).";

				output += "\nDate input must be in the format of mm/dd/yyyy\n\n";

				cout << output;
			}
			else
			{
				errMessage = utils.validateDateStringInput(date, day, month, year);

				if (errMessage != "")
					cout << errMessage;
				else
					validDateInput = true;
			}
		}
		else
		{
			cout << "\nInput was an incorrect length and must be in mm/dd/yyyy format.\n\n";
		}
	} while (validDateInput == false);
}