#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

class Price
{
public:
	Price(DBHelper &dbHelper) { this->dbHelper = dbHelper; }

	SQLSMALLINT code = 0;
	SQLCHAR name[BUFSIZ];
	SQLINTEGER won;

	DBHelper dbHelper;

	int16_t choose();
	int16_t del(Schedule &);
};

#endif // !PRICE_H