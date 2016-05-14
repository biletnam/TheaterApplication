#include "schedule.h"
#include <conio.h>

int16_t Schedule::chooseScreen()
{
	cout << "�󿵰� ����\n";
	
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	SQLCancel(stmt);
	SQLBindCol(stmt, 1, SQL_INTEGER, &screen.number, sizeof(screen.number), NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT number FROM screen;", SQL_NTS);
	
	for (int i = 1; SQL_SUCCESS == ret; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << screen.number << "��\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��� ������ �󿵰��� �����ϴ�\n";
				return FUNCTION_NULL;
			}
			else
			{
				return dbHelper.moveCursor(stmt, "\n�󿵰��� �����ϼ���");
			}
		}
	}
	
	cout << "������ �߻��߽��ϴ�.\n";
	_getch();
	return FUNCTION_ERROR;
}