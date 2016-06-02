#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

enum PriceInfo
{
	PRICE_CODE,
	PRICE_NAME,
	PRICE_WON,
};

class Price : public DBHelper
{
public:
	SQLINTEGER getCode();
	SQLCHAR *getName();
	SQLINTEGER getWon();

	void initialize();
	void show();

	FNRETURN input();
	FNRETURN inputCode();
	FNRETURN inputName();
	FNRETURN inputWon();

	SQLRETURN bindCol(MdfEnum);
	SQLRETURN bindCol(MdfEnum, PriceInfo);
	SQLRETURN bindParameter(MdfEnum, PriceInfo);

private:
	SQLINTEGER code = 0;
	SQLCHAR name[BUFSIZ] = {0};
	SQLINTEGER won = -1;
};

#endif // !PRICE_H