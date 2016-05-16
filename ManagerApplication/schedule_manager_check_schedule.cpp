#include "schedule_manager.h"

void ScheduleManager::checkSchedule()
{
	for (;;)
	{
		Schedule schedule(dbHelper);

		for (;;)
		{
			system("cls");
			cout <<
				"���� ���� �ý���\n"
				" > �� ���� ����\n"
				"  > �� ���� Ȯ�� / ����\n\n"

				"�� ���� ����\n";
			schedule.showInfo();
			cout << endl;

			if (schedule.screen.number != NULL)
			{
				break;
			}
			else if (schedule.date.value == NULL)
			{
				if (schedule.chooseDate() != FUNCTION_SUCCESS)
				{
					return;
				}
			}
			else if (schedule.chooseScreen() != FUNCTION_SUCCESS)
			{
				checkSchedule();
				return;
			}
		}

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT movie_code, movie_title, age, start_time, end_time "
			"FROM d%d "
			"WHERE screen=%d "
			"ORDER BY start_time ASC;",
			schedule.date.value, schedule.screen.number);

		SQLHSTMT &stmt = dbHelper.saleInfoStmt;
		SQLCancel(stmt);
		schedule.bindCol();
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		modifySchedule(schedule);

		for (int i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				schedule.showInfo();
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "��ϵ� �� ������ �����ϴ�\n"
						"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...\n";
					_getch();

					return;
				}
				else
				{
					cout << "0. ����\n";
					if (FUNCTION_SUCCESS == dbHelper.moveCursor(stmt, "\n������ �� ������ �����ϼ���: "))
					{						
						modifySchedule(schedule);
					}
				}
			}
		}
				
		cout << "������ �߻��߽��ϴ�.\n"
			"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
		_getch();
	}
}