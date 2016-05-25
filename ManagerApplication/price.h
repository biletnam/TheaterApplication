#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

class Price
{
public:
	SQLSMALLINT code = 0;
	SQLCHAR name[BUFSIZ];
	SQLINTEGER won;
	
	Price(DBHelper &);

	FNRETURN choose();

	FNRETURN inputCode();
	FNRETURN inputName();
	FNRETURN inputWon();

	FNRETURN bindCol(SQLHSTMT &);

private:
	DBHelper &dbHelper;
};

#endif // !PRICE_H