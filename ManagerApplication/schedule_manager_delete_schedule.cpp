#include "schedule_manager.h"

void ScheduleManager::deleteSchedule()
{
	Schedule schedule(dbHelper);

	for (;; schedule.date.value = NULL, schedule.screen.number = NULL)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 일정 확인 / 삭제\n\n"

			"상영 일정 정보\n";
		
		// 해결 x
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
			cout << schedule.screen.number << "관\n";
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
					cout << "\n등록된 상영 일정이 없습니다\n"
						"계속하려면 아무 키나 누르십시오...\n";
					_getch();

					return;
				}
				else
				{
					switch (dbHelper.moveCursor(stmt, "\n상영 일정을 선택하세요"))
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

		cout << "오류가 발생했습니다..\n"
			"계속하려면 아무 키나 누르십시오...";
		_getch();
		
		return;
	}
}
