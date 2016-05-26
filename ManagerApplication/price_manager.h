#pragma once
#include "price.h"

class PriceManager
{
public:
	PriceManager(DBHelper &);
private:
	DBHelper &dbHelper;

	void checkAndDeletePrice();
	void addPrice();
};

