#include "movie.h"

SQLINTEGER Movie::getCode()
{
	return code;
}

void Movie::setCode(SQLINTEGER code)
{
	this->code = code;
}
