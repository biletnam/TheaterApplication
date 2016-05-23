#include "DB_helper.h"

FNRETURN DBHelper::inputChoice()
{
	float choice;
	cin >> choice;

	if (cin.fail() == true
		|| choice < 0
		|| (choice - (int)choice) != 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		return FUNCTION_ERROR;
	}
	else
	{
		return (FNRETURN)choice;
	}
}