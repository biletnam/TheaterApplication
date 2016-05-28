#ifndef SCREEN_H
#define SCREEN_H

#include "DB_helper.h"

enum ScreenInfo
{
	SCREEN_NUMBER,
	SCREEN_ROW,
	SCREEN_COL,
};

class Screen
{
public:
	Screen(DBHelper &dbHelper) : dbHelper(dbHelper) {}
	SQLSMALLINT getNumber() const;

	SQLRETURN bindCol();

private:
	DBHelper &dbHelper;

	SQLSMALLINT number = 0;
	SQLSMALLINT row;
	SQLSMALLINT col;
};

#endif // !SCREEN_H
