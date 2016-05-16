#pragma once
#include "price.h"

class PriceManager
{
public:
	PriceManager(DBHelper &);
private:
	DBHelper dbHelper;

	FNRETURN checkPrice();
	FNRETURN addPrice();
};

