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
};

#endif // !PRICE_H