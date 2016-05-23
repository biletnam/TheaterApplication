#pragma once
#include <iostream>

using namespace std;

enum {
	FUNCTION_CANCEL = 0,
	FUNCTION_SUCCESS = -1,
	FUNCTION_NULL = -2,
	FUNCTION_ERROR = -3,
};

typedef int16_t FNRETURN;