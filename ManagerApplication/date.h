#pragma once

#include <time.h>
#include "DB_helper.h"

enum DateType
{
	DATE_YEAR,
	DATE_MONTH,
	DATE_DAY,
};

class Date : public DBHelper{
public:
	void show();
	void initialize() { value = 0; }
	SQLRETURN del();
	SQLRETURN insert();
	SQLRETURN prepare(SQLWCHAR *);
	SQLRETURN choose();

	FNRETURN input();
	FNRETURN input(DateType);

	int16_t get(DateType);
	int16_t getLastDay();
	int32_t getValue() const;
	static Date getToday();

	FNRETURN set(DateType, const int16_t);
	

	SQLRETURN bindCol();
	SQLRETURN bindParameter();

	bool isLeapYear(const int16_t);
	
private:
	int32_t value = 0;
};