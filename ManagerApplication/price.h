#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

class Price
{
public:
	Price(DBHelper &dbHelper) { this->dbHelper = dbHelper; }

	SQLSMALLINT code;
	SQLCHAR name[BUFSIZ];
	SQLINTEGER won;

	FNRETURN choose();

	FNRETURN inputCode();
	FNRETURN inputName();
	FNRETURN inputWon();

private:
	DBHelper dbHelper;
};

#endif // !PRICE_H