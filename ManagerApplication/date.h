#pragma once

#include <time.h>
#include "common_header.h"

class Date {
public:
	Date(const int32_t value = 0) : value(value) {}
	void show() const;

	FNRETURN inputYear();
	FNRETURN inputMonth();
	FNRETURN inputDay();

	int16_t getYear() const;
	int16_t getMonth() const;
	int16_t getLastDay();
	int16_t getDay() const;
	int32_t getValue() const;
	static Date getToday();

	bool setYear(const int16_t);
	bool setMonth(const int16_t);
	bool setDay(const int16_t);
	bool setValue(const int32_t);

	bool isLeapYear(const int16_t);
private:
	int32_t value;
	
};