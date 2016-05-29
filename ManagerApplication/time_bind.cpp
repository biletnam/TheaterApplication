#include "schedule.h"

SQLRETURN Schedule::Time::bindCol(MdfEnum mdf, TimeInfo timeInfo)
{
	switch (timeInfo)
	{
	case START_TIME:
		return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &startTime);
	case END_TIME:
	default:
		return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &endTime);
	}
}

SQLRETURN Schedule::Time::bindParameter(MdfEnum mdf, TimeInfo timeInfo)
{
	switch (timeInfo)
	{
	case START_TIME:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &startTime);
	case END_TIME:
	default:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &endTime);
	}
}