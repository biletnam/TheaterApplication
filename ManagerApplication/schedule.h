#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "movie.h"
#include "screen.h"
#include "Date.h"

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
		void initialize();
	private:
		SQLSMALLINT startTime = 0;
		SQLSMALLINT endTime = 0;
	};

	Movie movie;
	Screen screen;
	Date date;
	Time time;
	
	FNRETURN choose();
	FNRETURN chooseScreen();
	FNRETURN chooseMovie();

	FNRETURN inputTime(const SQLSMALLINT time);
	FNRETURN inputTime();
	FNRETURN checkTime(const SQLSMALLINT);
	
	SQLRETURN bindCol();
	SQLRETURN del();
	SQLRETURN prepare(SQLWCHAR *);

	void show();
	void initialize();
private:
};

#endif // !SCHEDULE_H