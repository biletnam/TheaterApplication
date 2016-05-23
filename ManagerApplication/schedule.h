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
	SQLSMALLINT startTime;
	SQLSMALLINT endTime;
	
	Schedule(DBHelper *pDBHelper = NULL) : pDBHelper(pDBHelper) {};

	FNRETURN chooseDate();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();
	FNRETURN inputTime();
	
	FNRETURN bindCol();

	void showInfo() const;
private:
	DBHelper *pDBHelper;

	FNRETURN inputTime(SQLSMALLINT& time, const char *output);
	FNRETURN checkTime(const SQLSMALLINT);
public:
	FNRETURN del();
};

#endif // !SCHEDULE_H