#include "schedule_manager.h"

void ScheduleManager::checkAndModifySchedule()
{
	for (;;)
	{
		Schedule schedule;

		for (;;)
		{
			system("cls");
			cout <<
				"���� ���� �ý���\n"
				" > �� ���� ����\n"
				"  > �� ���� Ȯ�� / ����\n\n"

				"�� ���� ����\n";
			schedule.show();
			cout << endl;

			if (schedule.screen.getNumber() != 0)
			{
				break;
			}
			else if (schedule.date.getValue() == 0)
			{
				switch (schedule.chooseDate())
				{
				case FUNCTION_CANCEL:
				case FUNCTION_NULL:
					return;
				}
			}
			else
			{
				switch (schedule.chooseScreen())
				{
				case FUNCTION_CANCEL:
				case FUNCTION_NULL:
					schedule.date.setValue(0);
				}
			}
		}

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT movie_code, movie_title, age, start_time, end_time "
			"FROM d%d "
			"WHERE screen=%d "
			"ORDER BY start_time ASC;",
			schedule.date.getValue(), schedule.screen.getNumber());

		SQLHSTMT &stmt = schedule.getStmt(MDF_SALE_INFO);
		SQLCancel(stmt);
		schedule.bindCol();
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);
		
		if (SQL_SUCCESS != ret)
		{
			cout << "������ �߻��߽��ϴ�(checkSchedule).\n";
			system("pause");
			return;
		}

		for (size_t i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				schedule.show();
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "��ϵ� �� ������ �����ϴ�\n";
					system("pause");
					return;
				}

				cout << 
					"0. ����\n"
					"\n"
					"������ �� ������ �����ϼ���: ";
				switch (schedule.moveCursor(MDF_SALE_INFO))
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					modifySchedule(schedule);
					break;
				default:
					cout << "������ �߻��߽��ϴ�(checkSchedule).\n";
					system("pause");
				}
			}
		}
	}
}