#include "movie.h"

SQLINTEGER Movie::getCode()
{
	return code;
}

void Movie::initialize()
{
	code = 0;
}