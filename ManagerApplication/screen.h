#ifndef SCREEN_H
#define SCREEN_H

#include "DB_helper.h"

class Screen
{
public:
	SQLSMALLINT number = 0;
	SQLSMALLINT row;
	SQLSMALLINT col;
};

#endif // !SCREEN_H
