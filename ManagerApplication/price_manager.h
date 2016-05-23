#pragma once
#include "price.h"

class PriceManager
{
public:
	PriceManager(DBHelper *);
private:
	DBHelper *pDBHelper;

	FNRETURN checkPrice();
	FNRETURN addPrice();
};

