#include "common_header.h"

FNRETURN inputPositiveInteger(int32_t positiveInteger)
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