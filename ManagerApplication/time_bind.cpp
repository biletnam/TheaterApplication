#include "schedule.h"

SQLRETURN Schedule::Time::bindCol(MdfEnum mdf, TimeInfo timeInfo)
{
	switch (timeInfo)
	{
	case START_TIME:
		return DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &startTime);
	case END_TIME:
	default:
		return DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &endTime);
	}
}

SQLRETURN Schedule::Time::bindParameter(MdfEnum mdf, TimeInfo timeInfo)
{
	switch (timeInfo)
	{
	case START_TIME:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &startTime);
	case END_TIME:
	default:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &endTime);
	}
}