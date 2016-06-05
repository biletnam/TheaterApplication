#include "price.h"

void Price::initialize()
{
	code = 0;
}

void Price::show() const
{
	wcout << name;
	cout << "(" << code << ") " << won << "¿ø\n";
}

SQLINTEGER Price::getCode() const
{
	return code;
}

const SQLWCHAR *Price::getName() const
{
	return name;
}

SQLINTEGER Price::getWon() const
{
	return won;
}