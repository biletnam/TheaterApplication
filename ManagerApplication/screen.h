#ifndef SCREEN_H
#define SCREEN_H

#include "DB_helper.h"

typedef enum
{
	SCREEN_NUMBER,
	SCREEN_ROW,
	SCREEN_COL,
} ScreenInfo;

class Screen
{
public:
	Screen(DBHelper &dbHelper) : dbHelper(dbHelper) {}
	SQLSMALLINT getNumber() const;

	SQLRETURN bindCol(MdfEnum, ScreenInfo);
	SQLRETURN bindParameter(MdfEnum, ScreenInfo);
private:
	DBHelper &dbHelper;

	SQLSMALLINT number = 0;
	SQLSMALLINT row;
	SQLSMALLINT col;
};

#endif // !SCREEN_H
