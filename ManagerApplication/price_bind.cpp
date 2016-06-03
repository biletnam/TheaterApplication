#include "price.h"

SQLRETURN Price::bindCol(MdfEnum mdf)
{
	if (SQL_SUCCESS == bindCol(mdf, PRICE_CODE)
		&& SQL_SUCCESS == bindCol(mdf, PRICE_NAME)
		&& SQL_SUCCESS == bindCol(mdf, PRICE_WON))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}

SQLRETURN Price::bindParameter(MdfEnum mdf)
{
	if (SQL_SUCCESS == bindParameter(mdf, PRICE_CODE)
		&& SQL_SUCCESS == bindParameter(mdf, PRICE_NAME)
		&& SQL_SUCCESS == bindParameter(mdf, PRICE_WON))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}

SQLRETURN Price::bindCol(MdfEnum mdf, PriceInfo priceInfo)
{
	switch (priceInfo)
	{
	case PRICE_CODE:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &code);
	case PRICE_NAME:
		return DBHelper::bindCol(mdf, BIND_STRING, name);
	case PRICE_WON:
	default:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &won);
	}
}

SQLRETURN Price::bindParameter(MdfEnum mdf, PriceInfo priceInfo)
{
	switch (priceInfo)
	{
	case PRICE_CODE:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &code);
	case PRICE_NAME:
		return DBHelper::bindParameter(mdf, BIND_STRING, name);
	case PRICE_WON:
	default:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &won);
	}
}