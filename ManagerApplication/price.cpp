#include "price.h"

Price::Price(DBHelper &dbHelper) : dbHelper(dbHelper) 
{}

FNRETURN Price::bindCol(SQLHSTMT &stmt)
{
	if (SQLBindCol(stmt, 1, SQL_INTEGER, &code, sizeof code, NULL) == SQL_SUCCESS
		&&SQLBindCol(stmt, 2, SQL_WVARCHAR, name, BUFSIZ, NULL) == SQL_SUCCESS
		&&SQLBindCol(stmt, 3, SQL_INTEGER, &won, sizeof won, NULL) == SQL_SUCCESS)
	{
		return FUNCTION_SUCCESS;
	}

	return FUNCTION_ERROR;
}

SQLRETURN Price::bindCol(MdfEnum mdf, PriceInfo priceInfo)
{
	switch (priceInfo)
	{
	case PRICE_CODE:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &code);
	case PRICE_NAME:
		return dbHelper.bindCol(mdf, BIND_STRING, name);
	case PRICE_WON:
	default:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &won);
	}
}

SQLRETURN Price::bindParameter(MdfEnum mdf, PriceInfo priceInfo)
{
	switch (priceInfo)
	{
	case PRICE_CODE:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &code);
	case PRICE_NAME:
		return dbHelper.bindParameter(mdf, BIND_STRING, name);
	case PRICE_WON:
	default:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &won);
	}
}

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

void Price::show()
{
	cout << name << "(" << code << ") " << won << "¿ø\n";
}