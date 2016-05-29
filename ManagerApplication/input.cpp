#include "common_header.h"

FNRETURN inputPositiveInteger(int32_t &positiveInteger)
{
	float input;
	cin >> input;

	if (cin.fail() == true)
	{
		cin.clear();
		cin.ignore(100, '\n');
	}
	else if (0 == input)
	{
		return FUNCTION_CANCEL;
	}
	else if (0 < input && 0 == (input - (int)input))
	{
		positiveInteger = (int32_t)input;
		return FUNCTION_SUCCESS;
	}

	return FUNCTION_ERROR;
}

FNRETURN inputYN(char &yn)
{
	char input[2];
	cin >> input;

	if (input[1] == 0)
	{
		switch (input[0])
		{
		case 'y': case 'Y':	case 'n': case 'N':
			yn = input[0];
			return FUNCTION_SUCCESS;
		}
	}

	return FUNCTION_ERROR;
}
