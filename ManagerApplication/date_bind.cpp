#include "date.h"

SQLRETURN Date::bindCol()
{
	return DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &value);
}

SQLRETURN Date::bindParameter()
{
	return DBHelper::bindParameter(MDF_THEATER, BIND_INTEGER, &value);
}
