#include "issue.h"

bool Issue::choosePrice()
{
	showInfo();

	bool isChosen = false;
	SQLINTEGER rowCount = 0;
	SQLINTEGER price;
	SQLINTEGER priceCode;
	SQLCHAR priceName[BUFSIZ];
	SQLWCHAR sql[BUFSIZ];
	SQLHSTMT& stmt = dbHelper.saleInfoStmt;
	
	swprintf_s(sql, 
		TEXT("SELECT price_id, price, price_name FROM d%d WHERE movie_code=%d AND time=%d;"),
		date, movieCode, startTime);
	SQLBindCol(stmt, 1, SQL_INTEGER, &priceCode, sizeof(priceCode), NULL);
	SQLBindCol(stmt, 2, SQL_INTEGER, &price, sizeof(price), NULL);
	SQLBindCol(stmt, 3, SQL_CHAR, priceName, sizeof(priceName), NULL);
	SQLExecDirect(stmt, sql, SQL_NTS);
	SQLRowCount(stmt, &rowCount);

	if (rowCount == 0)
	{
		cout << "�߱��� �� �����ϴ�.\n";
		return isChosen;
	}

	cout << "\n���\n";
	for (int i = 1; i <= rowCount + 1; i++)
	{
		SQLRETURN ret = SQLFetch(stmt);
		if (ret == SQL_SUCCESS)
		{
			cout << i << ". " 
				<< priceName << " " << price << "��\n";
		}
		else if (ret == SQL_NO_DATA)
		{
			if (dbHelper.moveCursor(stmt, "����� �����ϼ���") == true)
			{
				isChosen = true;
			}
		}
		else {
			cout << "������ �߻��߽��ϴ�.\n";
		}
	}

	for (int ticketCount = 1; ticketCount != 0 && isChosen == true;)
	{
		cout << "�ż��� �����ϼ���(0�� �Է��ϸ� ���): ";
		for (cin >> ticketCount; ticketCount > 0 && isChosen == true; ticketCount--)
		{
			showInfo();
			tickets.push_back(Ticket(priceCode, price, priceName));
			if (chooseSeat() == false)
			{
				isChosen = false;
			}
		}
	}

	return isChosen;
}