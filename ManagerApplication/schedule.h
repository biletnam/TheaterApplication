#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"

class Schedule {
public:
	Movie movie;
	Screen screen;
	Date date;
	SQLSMALLINT startTime = 0;
	SQLSMALLINT endTime = 0;
	
	Schedule(DBHelper &dbHelper) : dbHelper(dbHelper) {};

	FNRETURN chooseDate();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();
	FNRETURN inputTime();
	
	FNRETURN bindCol();

	void showInfo() const;
private:
	DBHelper &dbHelper;

	FNRETURN inputTime(SQLSMALLINT& time, const char *output);
	FNRETURN checkTime(const SQLSMALLINT);
public:
	FNRETURN del();
};

#endif // !SCHEDULE_H