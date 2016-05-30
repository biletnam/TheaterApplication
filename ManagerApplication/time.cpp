#include "schedule.h"

SQLSMALLINT Schedule::Time::getStartTime() const
{
	return startTime;
}

SQLSMALLINT Schedule::Time::getEndTime() const
{
	return endTime;
}

void Schedule::Time::show()
{
	cout << "시작 시간: " << startTime
		<< "\n종영 시간: " << endTime << endl;
}