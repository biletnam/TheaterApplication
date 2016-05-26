#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

class Price
{
public:
	SQLSMALLINT code = 0;
	SQLCHAR name[BUFSIZ] = {0};
	SQLINTEGER won = 0;
	
	Price(DBHelper &);

	void show();
	FNRETURN choose();

	FNRETURN inputCode();
	FNRETURN inputName();
	FNRETURN inputWon();

	FNRETURN bindCol(SQLHSTMT &);

private:
	DBHelper &dbHelper;
};

#endif // !PRICE_H