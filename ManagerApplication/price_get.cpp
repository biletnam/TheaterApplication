#include "price.h"

SQLINTEGER Price::getCode()
{
	return code;
}

SQLCHAR *Price::getName()
{
	return name;
}

SQLINTEGER Price::getWon()
{
	return won;
}