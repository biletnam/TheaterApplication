#ifndef SCREEN_H
#define SCREEN_H

#include "DB_helper.h"

typedef enum
{
	SCREEN_NUMBER,
	SCREEN_ROW,
	SCREEN_COL,
} ScreenInfo;

class Screen : public DBHelper
{
public:
	SQLSMALLINT getNumber() const;
	void show();
	void initialize();

	SQLRETURN bindCol();
	SQLRETURN bindCol(MdfEnum, ScreenInfo);
	SQLRETURN bindParameter(MdfEnum, ScreenInfo);
private:
	SQLSMALLINT number = 0;
	SQLSMALLINT row;
	SQLSMALLINT col;
};

#endif // !SCREEN_H
