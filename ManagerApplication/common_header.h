#pragma once
#include <iostream>

using namespace std;

typedef enum FUNCTION_RETURN
{
	FUNCTION_CANCEL = 0,
	FUNCTION_SUCCESS = -1,
	FUNCTION_ERROR = -2,
	FUNCTION_NULL = -3,
} FNRETURN;

FNRETURN inputPositiveInteger(int32_t &);
FNRETURN inputYN(char &);