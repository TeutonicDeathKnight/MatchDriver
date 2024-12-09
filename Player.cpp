#include <iostream>
#include <iomanip>
#include <string>
#include "FuncUtils.h"
#include "Person.h"
#include "Player.h"

using namespace std;

//<< operator overload function
ostream& operator<< (std::ostream& output, Player p)
{
	output << right << setw(25) << "Name - Position: "
		<< p.getLastName() << ", " << p.getFirstName() << " - " << p.getPosition() << '\n'
		<< setw(25) << "Jersey #: " << p.getJerseyNumber() << '\n'
		<< setw(25) << "Birth Date: " << p.getBirthDate() << '\n'
		<< setw(25) << "Years Played: " << p.getYearsPlayed() << '\n'
		<< setw(25) << "Graduation Date: " << p.getGraduationDate() << '\n'
		<< setw(25) << "Skill Level: " << p.getSkillLevel() << '\n'
		<< setw(25) << "Average Points per Game: "
		<< setprecision(6) << p.getAveragePointsPerGame() << "\n\n";

	return output;
}

//setYearsPlayed()
void Player::setYearsPlayed(int years) { yearsPlayed = years; }

//getYearsPlayed()
int Player::getYearsPlayed() const { return yearsPlayed; }

//setGraduationDate()
void Player::setGraduationDate(int day, int month, int year)
{
	graduationDate = Date(day, month, year);
}

//getGraduationDate()
string Player::getGraduationDate() const
{
	FuncUtils util = FuncUtils();

	return util.formatDate(graduationDate.getDay()
		, graduationDate.getMonth()
		, graduationDate.getYear());
}

//setPosition()
void Player::setPosition(string pos) { position = pos; }

//getPosition()
string Player::getPosition() const { return position; }

//setAveragePointsPerGame()
void Player::setAveragePointsPerGame(double avgPoints) { averagePointsPerGame = avgPoints; }

//getAveragePointsPerGame()
double Player::getAveragePointsPerGame() const { return averagePointsPerGame; }

//setSkillLevel()
void Player::setSkillLevel(string level) { skillLevel = level; }

string Player::getSkillLevel() const { return skillLevel; }

//default constructor
Player::Player()
	: Person()
{
	yearsPlayed = 0;
	graduationDate = Date();
	position = "";
	averagePointsPerGame = 0.0;
	skillLevel = "";
}

//multi argument constructor
Player::Player(int y, int gd, int gm, int gy, string pos, double avgPoints, string level
	, string l, string f, int bd, int bm, int by, string j)
	: Person(l, f, bd, bm, by, j)
{
	setYearsPlayed(y);
	setGraduationDate(gd, gm, gy);
	setPosition(pos);
	setAveragePointsPerGame(avgPoints);
	setSkillLevel(level);
}

//destructor
Player::~Player() {}