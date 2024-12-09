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