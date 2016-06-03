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
	
	SQLINTEGER getValue() const { return value; };
	int16_t get(DateType);
	int16_t getLastDay();
	static Date getToday();
	
	FNRETURN input();

	SQLRETURN bindCol();
	SQLRETURN bindParameter();

	bool isLeapYear(const int16_t);
private:
	FNRETURN input(DateType);
	FNRETURN set(DateType, const int16_t);

	SQLINTEGER value = 0;
};