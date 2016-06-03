#include "price.h"

SQLINTEGER Price::getCode()
{
	return code;
}

SQLWCHAR *Price::getName()
{
	return name;
}

SQLINTEGER Price::getWon()
{
	return won;
}