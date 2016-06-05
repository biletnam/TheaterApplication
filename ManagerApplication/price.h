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
	void show() const;
	SQLINTEGER getCode() const;
	const SQLWCHAR *getName() const;
	SQLINTEGER getWon() const;
	
	void initialize();
	FNRETURN input();
	SQLRETURN bindCol(MdfEnum);
	SQLRETURN bindParameter(MdfEnum);
	SQLRETURN bindCol(MdfEnum, PriceInfo);
	SQLRETURN bindParameter(MdfEnum, PriceInfo);
private:
	SQLINTEGER code = 0;
	SQLWCHAR name[BUFSIZ] = { 0 };
	SQLINTEGER won = -1;

	FNRETURN inputCode();
	FNRETURN inputName();
	FNRETURN inputWon();
};

#endif // !PRICE_H