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

//function prototypes
Match collectTeamInfo(FuncUtils& utils);
void menuPrompt(int numPlayers, char& sel);
void selectionTree(char sel, bool& progRun, Match* m);
void listMatchInfo(Match* m);

//main()
int main()
{
	cout << "Zachary Seeley -- Lab 7 - Inheritance / Operator Overloading\n\n\n";

	//create utility object to perform functions from utility library
	FuncUtils utils = FuncUtils();
	bool programRunning = true;

	Match match = collectTeamInfo(utils);

	do
	{
		char selection;

		menuPrompt(match.getMatchPlayersLength(), selection);

		if (selection != 'C' && selection != 'P' && selection != 'L' && selection != 'Q')
			continue;

		selectionTree(selection, programRunning, &match);


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
	string errMessageBase = "\n\nInput is blank and cannot be blank.\n";
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

	do
	{
		string date = utils.collectStringInput(prompt, errMessage);

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
	} while (validDateInput == false);

	cout << endl;

	system("pause");

	return Match(name, location, opponent, day, month, year);
}

//menuPrompt()
void menuPrompt(int numPlayers, char& sel)
{

	cout << "Main Menu\n\n"
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
void selectionTree(char sel, bool& progRun, Match* m)
{
	if (sel == 'C')
	{
		//add coach function here
	}
	else if (sel == 'P')
	{
		//add player function here
	}
	else if (sel == 'L')
		listMatchInfo(m);
	else if (sel == 'Q')
		progRun = false;
}

//listMatchInfo()
void listMatchInfo(Match* m)
{
	string errOutput = "";

	if (m->getMatchCoach().getTitle() == "")
		errOutput += "\nA coach has not been added to the match and needs to be added before "
			"the list will display.";
	if (m->getMatchPlayersLength() < 3)
		errOutput += "\nAll three players have not been added and need to be added before "
			"the list will display.";

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