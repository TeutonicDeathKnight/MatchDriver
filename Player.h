#pragma once
#include "Person.h"

//class to store data and functions related to the data
//	for a player assigned to a match
class Player
{
	friend std::ostream operator<< (std::ostream&, Player);
	//overloads the << operator to provide easy way to output class data

public:
	void setYearsPlayed(int years);
	//sets data member yearsPlayed value to passed in int value

	int getYearsPlayed() const;
	//returns data member yearsPlayed value

	void setGraduationDate(int day, int month, int year);
	//sets data member graduationDate value to passed in int values

	std::string getGraduationDate() const;
	//returns string value for data member graduationDate value

	void setPosition(std::string pos);
	//sets data member Position to passed in string value

	std::string getPosition() const;
	//returns data member position value

	void setAveragePointsPerGame(double avgPoints);
	//sets data member averagePointsPerGame value to passed in double value

	double getAveragePointsPerGame() const;
	//returns data member averagePointsPerGame value

	void setSkillLevel(std::string level);
	//sets data member skillLevel value to passed in string value

	Player();
	//zero argument constructor / default constructor

	Player(int y, int gd, int gm, int gy, std::string pos, double avgPoints, std::string level
		, std::string l, std::string f, int bd, int bm, int by, std::string j);
	//multiple argument constructor
	//	initializes Player data member variables to first 7 passed in values
	//	initializes inherited data member variables to last 6 passed in values

	~Player();
	//destructor

private:
	int yearsPlayed;
	//stores int data for player's years played

	Date graduationDate;
	//stores Date data for player's graduation date

	std::string position;
	//store string data for player's position
	//	setter, hitter, blocker, etc.

	double averagePointsPerGame;
	//stores double numeric data for player's average points per game

	std::string skillLevel;
	//stores string data for player's skill level
};