#include "issue.h"

bool Issue::chooseSeat()
{
	bool isChosen = false;
	SQLHSTMT& theaterStmt = dbHelper.theaterStmt;
	SQLHSTMT& scheduleStmt = dbHelper.saleInfoStmt;
	SQLWCHAR sql[BUFSIZ];
	Ticket& ticket = tickets.back();

	int recordCount;
	int row;
	int col;
	int feeId;
	
	swprintf_s(sql, TEXT("SELECT row, col, fee_id FROM d%ds%dt%d;"), 
		date, screen, startTime);
	SQLBindCol(scheduleStmt, 1, SQL_INTEGER, &row, sizeof(row), NULL);
	SQLBindCol(scheduleStmt, 2, SQL_INTEGER, &col, sizeof(col), NULL);
	SQLBindCol(scheduleStmt, 3, SQL_INTEGER, &feeId, sizeof(feeId), NULL);
	SQLRETURN ret = SQLExecDirect(scheduleStmt, sql, SQL_NTS);

	if (ret == SQL_ERROR)
	{
		SQLCancel(scheduleStmt);
		swprintf_s(sql, 
			TEXT("CREATE TABLE d%ds%dt%d ("
				"row    INT NOT NULL,"
				"col    INT NOT NULL,"
				"fee_id INT NOT NULL,"
				"PRIMARY KEY CLUSTERED(row ASC, col ASC)"
				");"), 
			date, screen, startTime);
		ret = SQLExecDirect(scheduleStmt, sql, SQL_NTS);
		if (ret == SQL_ERROR)
		{
			cout << "오류가 발생했습니다.\n";
			return isChosen;
		}
	}

	SQLRowCount(scheduleStmt, (SQLINTEGER*)&recordCount);

	if (recordCount == 0) {
		cout << "예매 가능한 좌석이 없습니다.\n";
		return isChosen;
	}

	cout << "\n좌석도(예매 가능한 좌석 o)\n"
		"----- screen -----\n";
	for (int i = 1; i <= maxRow; i++)
	{
		for (int j = 1; j <= maxCol; j++)
		{
			char seat = 'O';
			SQLFetchScroll(scheduleStmt, SQL_FETCH_FIRST, 0);
			for (int k = 0; k < recordCount; k++)
			{
				if (i == row && j == col)
				{
					seat = 'X';
				}
				SQLFetch(scheduleStmt);
			}
			cout << seat << ' ';
		}
		cout << endl;
	}
	SQLCancel(scheduleStmt);

	cout << "좌석을 선택하세요\n";
	do
	{
		cout << "행(0을 입력하면 종료): ";
		cin >> row;
		if (row == 0)
		{
			return isChosen;
		}
		cout << "열(0을 입력하면 종료): ";
		cin >> col;
		if (col == 0)
		{
			return isChosen;
		}

		swprintf_s(sql, TEXT("INSERT INTO d%ds%dt%d VALUES(%d, %d, %d);"),
			date, screen, startTime, row, col, ticket.priceCode);
		ret = SQLExecDirect(scheduleStmt, sql, SQL_NTS);
		if (ret != SQL_SUCCESS)
		{
			cout << "선택할 수 없는 좌석입니다\n\n";
		}
	} while (ret != SQL_SUCCESS);
	
	isChosen = true;
	ticket.setSeat(row, col);
	
	return isChosen;
}