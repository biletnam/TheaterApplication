#pragma once
#include <iostream>

using namespace std;

enum {
	FUNCTION_CANCEL = 0,
	FUNCTION_SUCCESS = -1,
	FUNCTION_ERROR = -2,
	FUNCTION_NULL = -3,
};

typedef int8_t FNRETURN;

FNRETURN inputInteger();