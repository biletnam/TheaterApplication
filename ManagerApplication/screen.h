#ifndef SCREEN_H
#define SCREEN_H

#include "DB_helper.h"

class Screen
{
public:
	Screen() {}

	SQLSMALLINT number;
	SQLSMALLINT row;
	SQLSMALLINT col;
};

#endif // !SCREEN_H
