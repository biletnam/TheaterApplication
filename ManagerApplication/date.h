#pragma once

#include <time.h>
#include "DB_helper.h"

class Date {
public:
	Date(DBHelper &dbHelper) : dbHelper(dbHelper) {}
	void show() const;
	FNRETURN showSelectResult();

	int16_t getYear() const;
	int16_t getMonth() const;
	int16_t getLastDay();
	int16_t getDay() const;
	int32_t getValue() const;
	static Date today(DBHelper &);

	FNRETURN setYear(const int16_t);
	FNRETURN setMonth(const int16_t);
	FNRETURN setDay(const int16_t);
	FNRETURN setValue(const int32_t);

	SQLRETURN bindCol();
	SQLRETURN bindParameter();

	bool isLeapYear(const int16_t);
	
private:
	int32_t value = 0;
	DBHelper &dbHelper;
};