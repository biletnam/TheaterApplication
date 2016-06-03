#include "price.h"

void Price::initialize()
{
	code = 0;
}

void Price::show()
{
	wcout << name;
	cout << "(" << code << ") " << won << "¿ø\n";
}

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