#pragma once

#include <time.h>
#include "common_header.h"

class Date {
public:
	int32_t value;
	
	Date(int32_t value = 0) : value(value) {}

	static Date getToday();
	void show() const;
	bool choose();

private:
	int16_t getYear() const;
	int16_t getMonth() const;
	int16_t getDay() const;

	void setYear(const int16_t);
	void setMonth(const int16_t);
	void setDay(const int16_t);

	bool chooseYear();
	bool chooseMonth();
	bool chooseDay();
};