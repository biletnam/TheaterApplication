#include "schedule_manager.h"

void ScheduleManager::deleteSchedule()
{
	for (;;)
	{
		Schedule schedule(dbHelper);

		do
		{
			system("cls");
			cout <<
				"���� ���� �ý���\n"
				" > �� ���� ����\n"
				"  > ���� Ȯ�� / ����\n\n"

				"�� ���� ����\n";
			schedule.showInfo();

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
				deleteSchedule();
				return;
			}
		} while (true);

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT movie_code, movie_title, age, start_time, end_time "
			"FROM d%d "
			"WHERE screen=%d;", schedule.date.value, schedule.screen.number);
			
		SQLHSTMT &stmt = dbHelper.saleInfoStmt;
		SQLCancel(stmt);
		schedule.bindCol();
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

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
					cout << "\n��ϵ� �� ������ �����ϴ�\n"
						"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...\n";
					_getch();

					return;
				}
				else
				{
					if (FUNCTION_SUCCESS 
						== dbHelper.moveCursor(stmt, "\n�� ������ �����ϼ���"))
					{
						deletePrice(schedule);
					}
				}
			}
		}

		cout << "������ �߻��߽��ϴ�..\n"
			"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
		_getch();
		
		return;
	}
}
