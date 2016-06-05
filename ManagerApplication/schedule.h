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
	Movie movie;
	Screen screen;
	Date date;

	void show() const;
	void showTime() const;
	SQLINTEGER getId() const { return id; };
	SQLINTEGER getStartTime() const { return startTime; }
	SQLINTEGER getEndTime() const { return endTime; }

	void initialize();
	FNRETURN inputTime();
	SQLRETURN bindCol();
	SQLRETURN bindParameter();
private:
	SQLINTEGER id = 0;
	SQLINTEGER startTime = 0;
	SQLINTEGER endTime = 0;

	bool isPossibleTime(SQLINTEGER);

	FNRETURN inputStartTime();
	FNRETURN inputEndTime();
};

#endif // !SCHEDULE_H
