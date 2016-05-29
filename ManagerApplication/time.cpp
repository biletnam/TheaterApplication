#include "schedule.h"

SQLSMALLINT Schedule::Time::getStartTime() const
{
	return startTime;
}

SQLSMALLINT Schedule::Time::getEndTime() const
{
	return endTime;
}