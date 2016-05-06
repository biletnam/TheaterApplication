#include "issue.h" 

void Issue::showTicket()
{
	SQLWCHAR sql[BUFSIZ];
	SQLHSTMT &stmt = dbHelper.salesRecordStmt;
	swprintf_s(sql,
		L"CREATE TABLE d%d"
		"("
		"Id INT NOT NULL PRIMARY KEY IDENTITY,"
		"number INT NOT NULL,"
		"movie_id INT NOT NULL,"
		"movie_name NVARCHAR(50) NOT NULL,"
		"screen INT NOT NULL,"
		"price_id INT NOT NULL,"
		"price_name NVARCHAR(50) NOT NULL,"
		"price INT NOT NULL,"
		"row INT NOT NULL,"
		"col INT NOT NULL"
		");",
		date);
	SQLExecDirect(stmt, sql, SQL_NTS);
	SQLCancel(stmt);

	for (int i = 0; i < tickets.size(); i++)
	{
		swprintf_s(sql,
			L"INSERT INTO"
			"d%d (number, movie_id, movie_name, start_time, screen, price_id, price_name, price, row, col)"
			"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
			,
			date);
		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
			sizeof(movieCode), 0, &movieCode, 0, NULL);
		SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
			BUFSIZ, 0, movieTitle, 0, NULL);
		SQLBindParameter(stmt, 3, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
			sizeof(startTime), 0, &startTime, 0, NULL);
		SQLBindParameter(stmt, 6, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
			sizeof(screen), 0, &screen, 0, NULL);
		SQLBindParameter(stmt, 7, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
			sizeof(tickets.at(i).priceCode), 0, &tickets.at(i).priceCode, 0, NULL);
		SQLBindParameter(stmt, 8, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
			BUFSIZ, 0, tickets.at(i).priceName, 0, NULL);
		SQLBindParameter(stmt, 9, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
			sizeof(tickets.at(i).price), 0, &tickets.at(i).price, 0, NULL);
		SQLExecDirect(stmt, sql, SQL_NTS);
		SQLCancel(stmt);
	}

	system("cls");

	int count = tickets.size();
	for (int i = 0; i < count; i++)
	{
		int hour = startTime / 100,
			minute = startTime % 100;
		cout << movieTitle << endl
			<< screen << "°ü " << hour << ":" << minute << endl;
		tickets.at(i).showSeatInfo();
	}
}