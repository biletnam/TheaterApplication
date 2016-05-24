#pragma once
#include <iostream>

using namespace std;

enum {
	FUNCTION_ERROR = -3,
	FUNCTION_NULL,
	FUNCTION_SUCCESS,
	FUNCTION_CANCEL,
};

typedef uint8_t FNRETURN;

FNRETURN inputInteger();