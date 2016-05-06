#pragma once

#include <time.h>
#include <iostream>
using namespace std;

class Date {
public:
	int32_t value;
	
	Date(int32_t value = 0) { this->value = value; }

	int32_t getToday() const;
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