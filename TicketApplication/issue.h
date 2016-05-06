#ifndef ISSUE_H
#define ISSUE_H

#include "DB/DBHelper.h"
#include "ticket.h"

#include <vector>

class Issue {
public:
	Issue(DBHelper&);
private:
	bool chooseDate();
	bool chooseMovie();
	bool chooseTime();
	bool choosePrice();
	bool chooseSeat();
	void showTicket();
	void showInfo();
	void cancelIssue();
	void refund();

	void setMaxRowCol();
	
	SQLINTEGER date;
	SQLINTEGER startTime;
	SQLINTEGER screen;
	SQLINTEGER maxRow;
	SQLINTEGER maxCol;
	SQLINTEGER movieCode;
	SQLCHAR movieTitle[BUFSIZ];
	vector<Ticket> tickets;
	DBHelper dbHelper;
};

#endif // !ISSUE_H