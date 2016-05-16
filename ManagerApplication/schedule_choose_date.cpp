#include "schedule.h"

int16_t Schedule::chooseDate()
{
	cout << "��¥ ����\n";

	SQLINTEGER today = date.getToday();
	today = 1;
	
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_C_LONG,
		sizeof(today), 0, &today, 0, NULL);
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
				cout << "��� ������ ���� �����ϴ�\n";
				return FUNCTION_NULL;
			}
			else 
			{
				cout << "0. ����\n";
				return dbHelper.moveCursor(stmt, "\n����: ");
			}
			break;
		default:
			cout << "������ �߻��߽��ϴ�.\n";
			return FUNCTION_ERROR;
		}
	}

	cout << "������ �߻��߽��ϴ�..\n"
		"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
	_getch();
	return FUNCTION_ERROR;
}