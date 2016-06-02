#include "schedule.h"

SQLRETURN Schedule::Time::bindCol(MdfEnum mdf, TimeType type)
{
	switch (type)
	{
	case START_TIME:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &startTime);
	case END_TIME:
	default:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &endTime);
	}
}

SQLRETURN Schedule::Time::bindParameter(MdfEnum mdf, TimeType type)
{
	switch (type)
	{
	case START_TIME:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &startTime);
	case END_TIME:
	default:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &endTime);
	}
}