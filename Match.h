#pragma once
#include "Coach.h"
#include "Player.h"

//stores data and functions related to the data
//	for a volleyball match
class Match
{
public:


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