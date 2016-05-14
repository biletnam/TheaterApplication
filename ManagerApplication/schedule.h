#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"

class Schedule {
public:
	DBHelper dbHelper;

	Movie movie;
	Screen screen;
	Date date = 0;
	SQLSMALLINT startTime = 0;
	SQLSMALLINT endTime = 0;
	
	Schedule(DBHelper& dbHelper) { this->dbHelper = dbHelper; };

	FNRETURN chooseDate();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();
	FNRETURN inputTime();
	
	FNRETURN bindCol();

	void showInfo();
private:
	FNRETURN inputTime(SQLSMALLINT& time, const char *output);
	FNRETURN checkTime(const SQLSMALLINT);
};

#endif // !SCHEDULE_H