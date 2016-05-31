#include "Date.h"

void Date::show()
{
	if (0 != get(DATE_YEAR))
	{
		cout << get(DATE_YEAR) << "�� ";
	}

	if (0 != get(DATE_MONTH))
	{
		cout << get(DATE_MONTH) << "�� ";
	}

	if (0 != get(DATE_DAY))
	{
		cout << get(DATE_DAY) << "��";
	}
	cout << endl;
}

SQLRETURN Date::bindCol()
{
	return DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &value);
}

SQLRETURN Date::bindParameter()
{
	return DBHelper::bindParameter(MDF_THEATER, BIND_INTEGER, &value);
}

SQLRETURN Date::prepare(SQLWCHAR *sql)
{
	return DBHelper::prepare(MDF_THEATER, sql);
}

SQLRETURN Date::choose()
{
	return DBHelper::choose(MDF_THEATER);
}
