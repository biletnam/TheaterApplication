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
		
	SQLRETURN bindCol();
	SQLRETURN bindParameter();

	void show();
	void showTime();
	void initialize();
	SQLINTEGER getId() { return id; };
	SQLINTEGER  getStartTime() { return startTime; }
	SQLINTEGER  getEndTime() { return endTime; }

	Movie movie;
	Screen screen;
	Date date;
private:
	FNRETURN inputStartTime();
	FNRETURN inputEndTime();
	bool isPossibleTime(SQLINTEGER);

	SQLINTEGER id = 0;
	SQLINTEGER startTime = 0;
	SQLINTEGER endTime = 0;
};

#endif // !SCHEDULE_H
