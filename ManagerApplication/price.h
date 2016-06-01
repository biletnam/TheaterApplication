#ifndef PRICE_H
#define PRICE_H

#include "DB_helper.h"

typedef enum
{
	PRICE_CODE,
	PRICE_NAME,
	PRICE_WON,
} PriceInfo;

class Price : public DBHelper
{
public:
	SQLINTEGER getCode();
	SQLCHAR *getName();
	SQLINTEGER getWon();

	void setCode(SQLSMALLINT);
	void setName(SQLCHAR *);
	void setWon(SQLSMALLINT);

	void initialize();
	void show();

	FNRETURN inputCode();
	FNRETURN inputName();
	FNRETURN inputWon();

	SQLRETURN bindCol(MdfEnum);
	SQLRETURN bindCol(MdfEnum, PriceInfo);
	SQLRETURN bindParameter(MdfEnum, PriceInfo);

private:
	SQLINTEGER code = 0;
	SQLCHAR name[BUFSIZ];
	SQLINTEGER won;
};

#endif // !PRICE_H