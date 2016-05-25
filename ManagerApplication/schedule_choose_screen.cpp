#include "schedule.h"

FNRETURN Schedule::chooseScreen()
{
	cout << "�󿵰� ����\n";
	
	SQLHSTMT &stmt = dbHelper.getStmt(THEATER);
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
				system("pause");

				return FUNCTION_NULL;
			}
			else
			{
				screen.number = 0;
				cout << "0. ����\n";
				return dbHelper.moveCursor(stmt, "\n����: ");
			}
		}
	}
	
	cout << "������ �߻��߽��ϴ�.\n";
	system("pause");

	return FUNCTION_ERROR;
}