#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

class Price
{
public:
	SQLSMALLINT code = 0;
	SQLCHAR name[BUFSIZ];
	SQLINTEGER won;

	int16_t choose(DBHelper &);
	int16_t del();
};

#endif // !PRICE_H