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
				"극장 관리 시스템\n"
				" > 상영 일정 관리\n"
				"  > 상영 일정 확인 / 수정\n\n"

				"상영 일정 정보\n";
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
					cout << "\n등록된 상영 일정이 없습니다\n"
						"계속하려면 아무 키나 누르십시오...\n";
					_getch();

					return;
				}
				else
				{
					if (FUNCTION_SUCCESS == dbHelper.moveCursor(stmt, "\n수정할 상영 일정을 선택하세요"))
					{
						
						modifySchedule(schedule);
					}
				}
			}
		}
				
		cout << "오류가 발생했습니다.\n"
			"계속하려면 아무 키나 누르십시오...";
		_getch();
	}
}


