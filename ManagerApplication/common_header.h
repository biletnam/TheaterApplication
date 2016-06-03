#pragma once
#include <iostream>

using namespace std;

enum FNRETURN
{
	FUNCTION_CANCEL = 0,
	FUNCTION_SUCCESS = -1,
	FUNCTION_ERROR = -2,
	FUNCTION_NULL = -3,
};

FNRETURN inputPositiveInteger(int32_t &);
FNRETURN inputYN();