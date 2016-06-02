#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"

enum ScheduleInfo
{
	SCHEDULE_MOVIE,
	SCHEDULE_SCREEN,
	SCHEDULE_DATE,
	SCHEDULE_START_TIME,
	SCHEDULE_END_TIME,
	SCHEDULE_ID,
};

class Schedule : public DBHelper {
public:
	FNRETURN inputTime();
	FNRETURN inputStartTime();
	FNRETURN inputEndTime();
	bool isPossibleTime(SQLINTEGER);
	
	SQLRETURN bindCol();
	SQLRETURN bindParameter();

	void show();
	void initialize();
	SQLINTEGER getId() { return id; };
	SQLSMALLINT getStartTime() { return startTime; }
	SQLSMALLINT getEndTime() { return endTime; }

	Movie movie;
	Screen screen;
	Date date;
private:
	SQLINTEGER id = 0;
	SQLSMALLINT startTime = 0;
	SQLSMALLINT endTime = 0;
};

#endif // !SCHEDULE_H
