#ifndef SCREEN_H
#define SCREEN_H

#include "DB_helper.h"

enum ScreenInfo
{
	SCREEN_NUMBER,
	SCREEN_ROW,
	SCREEN_COL,
};

class Screen : public DBHelper
{
public:
	SQLINTEGER  getNumber() const;
	void show();
	void initialize();

	SQLRETURN bindCol();
	SQLRETURN bindCol(MdfEnum, ScreenInfo);
	SQLRETURN bindParameter(MdfEnum, ScreenInfo);
private:
	SQLINTEGER number = 0;
	SQLINTEGER row = 0;
	SQLINTEGER col = 0;
};

#endif // !SCREEN_H
