#include "screen.h"

SQLSMALLINT Screen::getNumber() const
{
	return number;
}

SQLRETURN Screen::bindCol(MdfEnum mdf, ScreenInfo screenInfo)
{
	switch (screenInfo)
	{
	case SCREEN_NUMBER:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &number);
	case SCREEN_COL:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &col);
	case SCREEN_ROW:
	default:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &row);
	}
}

SQLRETURN Screen::bindParameter(MdfEnum mdf, ScreenInfo screenInfo)
{
	switch (screenInfo)
	{
	case SCREEN_NUMBER:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &number);
	case SCREEN_COL:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &col);
	case SCREEN_ROW:
	default:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &row);
	}
}
