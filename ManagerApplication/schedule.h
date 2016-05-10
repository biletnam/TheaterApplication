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

	int16_t chooseDate();
	int16_t chooseScreen();
	int16_t chooseMovie();
	int16_t inputTime();
	
	int16_t bindCol();

	void showInfo();
private:
	int16_t inputTime(SQLSMALLINT& time, const char *output);
	int16_t checkTime(const SQLSMALLINT);
};

#endif // !SCHEDULE_H