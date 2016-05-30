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

class Schedule : public DBHelper {
public:
	class Time : public DBHelper
	{
	public:
		SQLSMALLINT getStartTime() const;
		SQLSMALLINT getEndTime() const;

		SQLRETURN bindCol(MdfEnum, TimeInfo);
		SQLRETURN bindParameter(MdfEnum, TimeInfo);

		void show();
	private:
		SQLSMALLINT startTime = 0;
		SQLSMALLINT endTime = 0;
	};

	Schedule() {}

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
};

#endif // !SCHEDULE_H