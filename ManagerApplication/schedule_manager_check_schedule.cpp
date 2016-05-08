#include "schedule_manager.h"

void ScheduleManager::checkSchedule()
{
	system("cls");
	cout << "상영 일정 확인\n";

	Schedule schedule(dbHelper);
	schedule.chooseDate();
	schedule.chooseScreen();
	
	// saleinfo select
	SQLHSTMT &stmt = dbHelper.saleInfoStmt;
	SQLWCHAR sql[BUFSIZ];
	swprintf_s(sql,	L""
		"SELECT movie_code, movie_title, age, start_time, end_time FROM d%d "
		"WHERE screen = %d "
		"ORDER BY start_time ASC;", schedule.date.value, schedule.screen.number);
	
	schedule.bindCol();

	SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ".";
			schedule.showInfo();
			cout << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "등록된 일정이 없습니다.\n"
					"계속하려면 아무 키나 누르십시오...";
				_getch();
				
			}
			else 
			{
				switch (dbHelper.moveCursor(stmt, "일정을 선택하세요"))
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					return;
				case FUNCTION_ERROR:
					break;
				}
			}
		default:
			break;
		}
	}

	cout << "오류가 발생했습니다..\n"
		"계속하려면 아무 키나 누르십시오...";
	_getch();
}


