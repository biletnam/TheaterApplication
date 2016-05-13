#include "schedule_manager.h"

void ScheduleManager::deleteSchedule()
{
	Schedule schedule(dbHelper);

	for (;; schedule.date.value = NULL, schedule.screen.number = NULL)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ�� / ����\n\n"

			"�� ���� ����\n";
		
		// �ذ� x
		if (NULL == schedule.date.value)
		{
			switch (schedule.chooseDate())
			{
			case FUNCTION_SUCCESS:
				break;
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_ERROR:
				continue;
			default:
				break;
			}
		}
		else
		{
			schedule.date.show();
		}

		if (NULL == schedule.screen.number)
		{
			switch (schedule.chooseDate())
			{
			case FUNCTION_SUCCESS:
				break;
			case FUNCTION_CANCEL:
				
			case FUNCTION_ERROR:
				continue;
			default:
				break;
			}
		}
		else
		{
			cout << schedule.screen.number << "��\n";
		}
		
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
					switch (dbHelper.moveCursor(stmt, "\n�� ������ �����ϼ���"))
					{
					case FUNCTION_SUCCESS:
					{
					}
					return;
					case FUNCTION_CANCEL:
						return;
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
