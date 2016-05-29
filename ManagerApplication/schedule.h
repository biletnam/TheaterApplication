#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"
#include "price.h"

enum TimeInfo
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
		SQLSMALLINT getStartTime() const;
		SQLSMALLINT getEndTime() const;

		SQLRETURN bindCol(MdfEnum, TimeInfo);
		SQLRETURN bindParameter(MdfEnum, TimeInfo);

		
	private:
		SQLSMALLINT startTime = 0;
		SQLSMALLINT endTime = 0;

		DBHelper &dbHelper;
	};

	Schedule(DBHelper &dbHelper) : 
		dbHelper(dbHelper), 
		movie(dbHelper), 
		screen(dbHelper), 
		date(dbHelper), 
		time(dbHelper), 
		price(dbHelper) {};

	Movie movie;
	Screen screen;
	Date date;
	Time time;
	Price price;
	
	FNRETURN chooseDate();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();

	FNRETURN inputTime(const SQLSMALLINT time);
	FNRETURN inputTime();
	FNRETURN checkTime(const SQLSMALLINT);
	
	FNRETURN bindCol();
	void del();

	void show();
private:
	DBHelper &dbHelper;
};

#endif // !SCHEDULE_H