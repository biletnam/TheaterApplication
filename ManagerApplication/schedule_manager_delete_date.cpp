#include "schedule_manager.h"

void ScheduleManager::deleteDate()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ��/����\n"
			"\n";

		SQLHSTMT &stmt = dbHelper.getStmt(THEATER);
		SQLCancel(stmt);
		Date date;
		SQLBindCol(stmt, 1, SQL_INTEGER, &date.value, sizeof date.value, NULL);

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L"SELECT date FROM schedule WHERE date>%d;", Date::getToday());
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				date.show();
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "��ϵ� �� ������ �����ϴ�\n";
					system("pause");
					return;
				}

				cout << "0. ����\n";
				switch (dbHelper.moveCursor(stmt, "\n������ �� ������ �����ϼ���: "))
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					break;
				default:
					cout << "������ �߻��߽��ϴ�(checkSchedule).\n";
					system("pause");
				}
			}
		}
	}
}
