#include "common_header.h"

FNRETURN inputPositiveInteger(int32_t &positiveInteger)
{
	float input;
	cin >> input;
	cin.clear();
	cin.ignore(100, '\n');
	
	if (0 == input)
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

FNRETURN inputYN()
{
	char input[BUFSIZ];
	cin.getline(input, BUFSIZ);

	if (input[1] == 0)
	{
		switch (input[0])
		{
		case 'y': case 'Y':
			return FUNCTION_SUCCESS;
		case 'n': case 'N':
			return FUNCTION_CANCEL;
		}
	}

	return FUNCTION_ERROR;
}
