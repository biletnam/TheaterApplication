#include "issue.h"
#include <time.h>

int getToday();

bool Issue::chooseDate()
{	
	showInfo();

	bool isChosen = false;
	SQLINTEGER rowCount = 0;
	SQLINTEGER date;
	SQLINTEGER today = getToday();

	today = 160301;

	SQLHSTMT& stmt = dbHelper.theaterStmt;
	
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
		sizeof(today), 0, &today, 0, NULL);
	SQLBindCol(stmt, 1, SQL_INTEGER, &date, sizeof(date), NULL);
	SQLExecDirect(stmt, TEXT("SELECT date FROM schedule WHERE date >= ?;"), SQL_NTS);
	SQLRowCount(stmt, &rowCount);
	
	if (rowCount == 0)
	{
		cout << "������ ���� �����ϴ�.\n";
		return isChosen;
	}

	cout << "\n���� ������(1�� ����)\n";
	for (int i = 1; i <= rowCount + 1; i++)
	{	
		SQLRETURN ret = SQLFetch(stmt);
		if (ret == SQL_SUCCESS)
		{
			int year = date / 10000;
			int month = (date % 10000) / 100;
			int day = (date % 100);
			cout << i << ". "
				<< year << "�� " 
				<< month << "�� " 
				<< day << "��\n";
		}
		else if (ret == SQL_NO_DATA)
		{
			if (dbHelper.moveCursor(stmt, "\n��¥�� �����ϼ���") == true)
			{
				this->date = date;
				isChosen = true;
			}
		}
		else 
		{
			cout << "������ �߻��߽��ϴ�.\n";
			return isChosen;
		}
	}
	
	return isChosen;
}

int getToday()
{
	struct tm t;
	time_t timer = time(NULL);

	localtime_s(&t, &timer);

	return (t.tm_year - 100) * 10000
		+ (t.tm_mon + 1) * 100
		+ t.tm_mday;
}