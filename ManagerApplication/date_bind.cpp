#include "date.h"

SQLRETURN Date::bindCol()
{
	return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &value);
}

SQLRETURN Date::bindParameter()
{
	return dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &value);
}
