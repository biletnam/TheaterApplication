#ifndef TICKET_H
#define TICKET_H

#include "db/DBHelper.h"

class Ticket
{
public:
	Ticket(SQLINTEGER, SQLINTEGER, SQLCHAR*);
	void setSeat(int, int);
	SQLINTEGER getPriceId();
	void showSeatInfo();

	SQLINTEGER row;
	SQLINTEGER col;
	SQLINTEGER price;
	SQLINTEGER priceCode;
	SQLCHAR priceName[BUFSIZ];
private:
};

#endif // !TICKET_H