#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "FuncUtils.h"
#include "Coach.h"
#include "Player.h"
#include "Match.h"

using namespace std;

//setNameTeam()
void Match::setNameTeam(string name) { nameTeam = name; }

//getNameTeam()
string Match::getNameTeam() const { return nameTeam; }

//setMatchLocation()
void Match::setMatchLocation(string location) { matchLocation = location; }

//getMatchLocation()
string Match::getMatchLocation() const { return matchLocation; }

//setMatchOpposition()
void Match::setMatchOpposition(string opposition) { matchOpposition = opposition; }

//getMatchOpposition()
string Match::getMatchOpposition() const { return matchOpposition; }

//setMatchDate()
void Match::setMatchDate(int day, int month, int year)
{
	matchDate = Date(day, month, year);
}

//getMatchDate()
string Match::getMatchDate() const
{
	FuncUtils util = FuncUtils();

	return util.formatDate(matchDate.getDay()
		, matchDate.getMonth()
		, matchDate.getYear());
}

//setMatchCoach()
void Match::setMatchCoach(Coach* coach) { matchCoach = *coach; }

//getMatchCoach()
Coach Match::getMatchCoach() { return matchCoach; }

//setMatchPlayers
void Match::setMatchPlayers(Player* player)
{
	if (matchPlayers.size() <= 3 && matchPlayers.size() >= 0)
		matchPlayers.push_back(*player);
}

//getMatchPlayers
vector<Player> Match::getMatchPlayers() const { return matchPlayers; }

//sortPlayers()
void Match::sortPlayers()
{
	sort(matchPlayers.begin(), matchPlayers.end()
		, [](const Player& lpl, const Player& rpl)
		{return lpl.getLastName() < rpl.getLastName();});
}

//ListMatchInformation()
void Match::listMatchInformation() const
{
	cout << "Match Information\n\n"
		<< right << setw(25) << "Match Date: " << getMatchDate() << '\n'
		<< setw(25) << "Team Name: " << getNameTeam() << '\n'
		<< setw(25) << "Match Location: " << getMatchLocation() << '\n'
		<< setw(25) << "Match Opponent: " << getMatchOpposition() << "\n\n"
		<< "COACH\n" << matchCoach
		<< "PLAYERS\n" << setw(25) << "#1:\n" << matchPlayers[0]
		<< setw(25) << "#2:\n" << matchPlayers[1]
		<< setw(25) << "#3:\n" << matchPlayers[2];
}

//getMatchPlayersLength()
int Match::getMatchPlayersLength() const { return matchPlayers.size(); }

//default / zero argument constructor
Match::Match()
{
	setNameTeam("");
	setMatchLocation("");
	setMatchOpposition("");
	matchDate = Date();
	matchCoach = Coach();
	matchPlayers = vector<Player>();
}

//multiple argument constructor
Match::Match(std::string n, std::string l, std::string o, int d, int m, int y)
{
	setNameTeam(n);
	setMatchLocation(l);
	setMatchOpposition(o);
	setMatchDate(d, m, y);
	matchCoach = Coach();
	matchPlayers = vector<Player>();
}

//destructor
Match::~Match() {}