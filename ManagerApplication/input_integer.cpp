#include "common_header.h"

FNRETURN inputInteger()
{
	float input;
	cin >> input;

	if (cin.fail() == true)
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
	else if (input >= 0 && (input - (int)input) == 0)
	{
		return (FNRETURN)input;
	}

	return FUNCTION_ERROR;
}