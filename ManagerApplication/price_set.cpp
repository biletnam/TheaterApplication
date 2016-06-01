#include "price.h"

void Price::setCode(SQLSMALLINT code)
{
	this->code = code;
}

void Price::setName(SQLCHAR *name)
{
	strcpy_s((char*)this->name, BUFSIZ, (char*)name);
}

void Price::setWon(SQLSMALLINT wond)
{
	this->won = won;
}