#include "schedule.h"
#include <conio.h>

int16_t Schedule::chooseScreen()
{
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	SQLBindCol(stmt, 1, SQL_INTEGER, &screen.number, sizeof(screen.number), NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT number FROM screen;", SQL_NTS);

	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". ��ũ��" << screen.number << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��� ������ �󿵰��� �����ϴ�\n";
				return FUNCTION_NULL;
			}
			else
			{
				switch (dbHelper.moveCursor(stmt, "\n�󿵰��� �����ϼ���"))
				{
				case FUNCTION_SUCCESS:
					return FUNCTION_SUCCESS;
				case FUNCTION_CANCEL:
					return FUNCTION_CANCEL;
				case FUNCTION_ERROR:
					return FUNCTION_ERROR;
				}
			}
		default:
			cout << "������ �߻��߽��ϴ�.\n";
			_getch();
			return FUNCTION_ERROR;
		}
	}

	return FUNCTION_ERROR;
}