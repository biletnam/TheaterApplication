#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ��/����\n"
			"\n";

		SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);
		SQLCancel(stmt);
		Date date;
		SQLBindCol(stmt, 1, SQL_INTEGER, &date.value, sizeof date.value, NULL);

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L"SELECT date FROM schedule WHERE date>%d;", Date::getToday().value);
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		if (SQL_SUCCESS != ret)
		{
			cout << "������ �߻��߽��ϴ�(checkSchedule).\n";
			system("pause");
			return;
		}

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
					cout << "��ϵ� ������ �����ϴ�\n";
					system("pause");
					return;
				}

				cout << "0. ����\n";
				switch (dbHelper.moveCursor(MDF_THEATER, "\n������ ������ �����ϼ���: "))
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					cout << "������ �߻��߽��ϴ�(checkSchedule).\n";
					system("pause");
				}
			}
		}
	}
}