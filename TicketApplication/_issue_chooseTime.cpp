#include "issue.h"

bool Issue::chooseTime()
{
	showInfo();

	bool isChosen = false;
	int rowCount = 0;
	int time;
	int screen;
	SQLWCHAR sql[BUFSIZ];
	SQLHSTMT& stmt = dbHelper.saleInfoStmt;

	swprintf_s(sql, 
		TEXT("SELECT time, screen FROM d%d WHERE movie_code=%d;"), 
		date, movieCode);
	SQLBindCol(stmt, 1, SQL_INTEGER, &time, sizeof(time), NULL);
	SQLBindCol(stmt, 2, SQL_INTEGER, &screen, sizeof(screen), NULL);
	SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);
	SQLRowCount(stmt, (SQLINTEGER*)&rowCount);

	if (rowCount == 0)
	{
		cout << "예정된 상영이 없습니다.\n";
		return isChosen;
	}

	cout << "\n상영 시간\n";
	for (int i = 1; i <= rowCount + 1; i++)
	{
		SQLRETURN ret = SQLFetch(stmt);
		if (ret == SQL_SUCCESS)
		{
			int hour = time / 100;
			int minute = time % 100;

			cout << i << ". "
				<< hour << "시 " << minute << "분\n";
		}
		else if (ret == SQL_NO_DATA)
		{
			if (dbHelper.moveCursor(stmt, "시간을 선택하세요") == true)
			{				
				this->screen = screen;
				this->startTime = time;
				setMaxRowCol();
				isChosen = true;
			}
		}
		else
		{
			cout << "오류가 발생했습니다.\n";
			return isChosen;
		}
	}

	return isChosen;
}