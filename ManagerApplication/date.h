#ifndef TIME_H
#define TIME_H

#include <time.h>
#include "DB_helper.h"

enum DateType
{
	DATE_YEAR,
	DATE_MONTH,
	DATE_DAY,
};

class Date : public DBHelper
{
public:
	void show() const;
	SQLINTEGER getValue() const { return value; };
	int16_t get(DateType) const;
	int16_t getLastDay() const;
	static Date getToday();
	bool isLeapYear(const int16_t) const;

	void initialize() { value = 0; }
	SQLRETURN bindCol();
	SQLRETURN bindParameter();
	FNRETURN input();
private:
	SQLINTEGER value = 0;

	FNRETURN set(DateType, const int16_t);
	FNRETURN input(DateType);
};

#endif // !TIME_H