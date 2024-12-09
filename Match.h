#pragma once
#include <vector>
#include "Coach.h"
#include "Player.h"

//stores data and functions related to the data
//	for a volleyball match
class Match
{
public:
	void setNameTeam(std::string name);
	//sets member variable nameTeam to passed in value to name

	std::string getNameTeam() const;
	//returns string value for member variable nameTeam value

	void setMatchLocation(std::string location);
	//sets member variable matchLocation to passed in value to location

	std::string getMatchLocation() const;
	//returns string value for member variable matchLocation value

	void setMatchOpposition(std::string opposition);
	//sets member variable matchOpposition to value passed into opposition

	std::string getMatchOpposition() const;
	//returns string value for member variable matchOpposition value

	void setMatchDate(int day, int month, int year);
	//sets member variable matchDate to passed in Date object

	std::string getMatchDate() const;
	//returns string value for member variable matchDate value

	void setMatchCoach(Coach* coach);
	//sets member variable matchCoach value to passed in Coach object

	Coach getMatchCoach();
	//returns Coach value for member variable matchCoach value 

	void setMatchPlayers(Player* player);
	//sets next vector<Player> object value to passed in player object

	std::vector<Player> getMatchPlayers() const;
	//returns vector<Player> object value for member variable matchPlayers

	void sortPlayers();
	//sorts member variable matchPlayers by last name
	//	uses sort() from the <algorithm> library

	void listMatchInformation() const;
	//displays all match information, outputting all member variables in a formatted way

	int getMatchPlayersLength() const;
	//returns int value for length of matchPlayers vector

	Match();
	//default / zero argument constructor
	//	initializes member variables to empty or default values

	Match(std::string n, std::string l, std::string o, int d, int m, int y);
	//multi argument constructor
	//	initializes string variables to passed in string values
	//	initializes date variable to passed in int values
	//	initializes Coach variable to an empty object
	//	initializes vector variable to empty vector

	~Match();
	//destructor

private:
	std::string nameTeam;
	//stores string data for team name value

	std::string matchLocation;
	//stores string data for match location value

	std::string matchOpposition;
	//stores string data for match opposing team value

	Date matchDate;
	//stores Date data for match date value

	Coach matchCoach;
	//stores Coach data for match coach value

	std::vector<Player> matchPlayers;
	//stores Player data for match players
	//	list must be 3 in length and cannot be shorter or longer before display of players
};