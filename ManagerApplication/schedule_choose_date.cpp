#include "schedule.h"

FNRETURN Schedule::chooseDate()
{
	cout << "��¥ ����\n";

	//Date today = Date::getToday();
	Date today(1);
	
	SQLHSTMT &stmt = dbHelper.getStmt(THEATER);
	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_C_LONG,
		sizeof today.value, 0, &today.value, 0, NULL);
	SQLBindCol(stmt, 1, SQL_INTEGER, &date.value, sizeof(date.value), NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT date FROM schedule WHERE date > ?;", SQL_NTS);
	
	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". ";
			date.show();
			cout << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "���� ������ ���� �����ϴ�\n";
				system("pause");
				return FUNCTION_NULL;
			}
			else
			{
				date.value = 0;
				cout << "0. ����\n";
				return dbHelper.moveCursor(stmt, "\n����: ");
			}
		}
	}

	cout << "������ �߻��߽��ϴ�..\n";
	system("pause");
	return FUNCTION_ERROR;
}