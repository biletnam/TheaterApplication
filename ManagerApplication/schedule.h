#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"

enum TimeEnum
{
	START_TIME,
	END_TIME,
};

class Schedule {
public:
	class Time
	{
	public:
		Time(DBHelper &dbHelper) : dbHelper(dbHelper) {}

		SQLRETURN bindCol();
	private:
		SQLSMALLINT startTime = 0;
		SQLSMALLINT endTime = 0;

		DBHelper &dbHelper;
	};


	Schedule(DBHelper &dbHelper) 
		: dbHelper(dbHelper), movie(dbHelper), screen(dbHelper), date(dbHelper)	{};

	Movie movie;
	Screen screen;
	Date date;
	Time time;
	
	FNRETURN chooseDate();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();
	FNRETURN inputTime();
	
	FNRETURN bindCol();
	void del();

	void showInfo() const;
private:
	DBHelper &dbHelper;

	FNRETURN inputTime(SQLSMALLINT& time, const char *output);
	FNRETURN checkTime(const SQLSMALLINT);
};

#endif // !SCHEDULE_H