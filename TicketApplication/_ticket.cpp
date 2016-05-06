#include "ticket.h"

Ticket::Ticket(SQLINTEGER priceId, SQLINTEGER price, SQLCHAR *priceName)
{
	this->priceCode = priceId;
	this->price = price;
	strcpy_s((char*)this->priceName, BUFSIZ, (char*)priceName);
}

void Ticket::setSeat(int row, int col)
{
	this->row = row;
	this->col = col;
}

SQLINTEGER Ticket::getPriceId()
{
	return priceCode;
}

void Ticket::showSeatInfo()
{
	cout << row << "ї­ " << col << "За\n"
		<< priceName << " " << price << "їш\n\n";
}
