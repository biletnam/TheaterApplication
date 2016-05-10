#include "schedule_manager.h"
#include <conio.h>

void ScheduleManager::deleteSchedule()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n\n"
			"  > 일정 확인 / 삭제\n";

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
			"SELECT movie_code, movie_title, age, start_time, end_time, age"
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
				dbHelper.moveCursor(stmt, "삭제할 일정을 삭제하세요");
				break;
			default:
				cout << "오류가 발생했습니다.\n";
				_getch();
			}
		}

		SQLINTEGER id;
		SQLGetData(stmt, 1, SQL_INTEGER, &id, sizeof(id), NULL);
		swprintf_s(sql,	L"DELETE FROM d%d WHERE id=%d;", schedule.date, id);

		if (SQLExecDirect(stmt, sql, SQL_NTS) == SQL_SUCCESS)
		{
			cout << "성공\n";
		}
		else
		{
			cout << "실패\n";
		}
		SQLCancel(stmt);
	}
}