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
	cout << "���� �ð�: " << startTime
		<< "\n���� �ð�: " << endTime << endl;
}