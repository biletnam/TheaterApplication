#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"

enum TimeType
{
	START_TIME,
	END_TIME,
};

class Schedule : public DBHelper {
public:
	FNRETURN choose();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();

	FNRETURN inputTime();
	FNRETURN inputStartTime();
	FNRETURN inputEndTime();
	bool isPossibleTime(SQLINTEGER);
	
	SQLRETURN bindParameter(MdfEnum);
	SQLRETURN bindCol();
	SQLRETURN prepare(SQLWCHAR *);

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
