#include "schedule_manager.h"

void ScheduleManager::deleteSchedule()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n\n"
			"  > ���� Ȯ�� / ����\n";

		Schedule schedule(dbHelper);
		
		if (schedule.chooseScreen() == FUNCTION_SUCCESS
			&& schedule.chooseDate() == FUNCTION_SUCCESS)
		{
			schedule.bindCol();
		}
		else
		{
			return;
		}

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT movie_code, movie_title, age, start_time, end_time"
			"FROM d%d "
			"WHERE screen=%d", schedule.date.value, schedule.screen.number);

		SQLHSTMT &stmt = dbHelper.saleInfoStmt;
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 0; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				schedule.showInfo();
				break;
			case SQL_NO_DATA:
				switch (dbHelper.moveCursor(stmt, "\n������ �����ϼ���"))
				{
				case FUNCTION_SUCCESS:
				{
					Price price;
				}
					return;
				case FUNCTION_CANCEL:
					return;
				}
			}
		}

		cout << "������ �߻��߽��ϴ�..\n"
			"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
		_getch();
		
		return;

		/*
		SQLINTEGER id;
		SQLGetData(stmt, 1, SQL_INTEGER, &id, sizeof(id), NULL);
		swprintf_s(sql,	L"DELETE FROM d%d WHERE id=%d;", schedule.date, id);

		if (SQLExecDirect(stmt, sql, SQL_NTS) == SQL_SUCCESS)
		{
			cout << "����\n";
		}
		else
		{
			cout << "����\n";
		}
		SQLCancel(stmt);*/
	}
}