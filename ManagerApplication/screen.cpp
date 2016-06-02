#include "screen.h"

SQLSMALLINT Screen::getNumber() const
{
	return number;
}

void Screen::show()
{
	cout << "»ó¿µ°ü " << number << endl;
}

void Screen::initialize()
{
	number = 0;
}

SQLRETURN Screen::bindCol(MdfEnum mdf, ScreenInfo screenInfo)
{
	switch (screenInfo)
	{
	case SCREEN_NUMBER:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &number);
	case SCREEN_COL:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &col);
	case SCREEN_ROW:
	default:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &row);
	}
}

SQLRETURN Screen::bindParameter(MdfEnum mdf, ScreenInfo screenInfo)
{
	switch (screenInfo)
	{
	case SCREEN_NUMBER:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &number);
	case SCREEN_COL:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &col);
	case SCREEN_ROW:
	default:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &row);
	}
}
