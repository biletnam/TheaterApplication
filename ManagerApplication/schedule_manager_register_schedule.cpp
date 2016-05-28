#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	for (;;)
	{
		Schedule schedule(dbHelper);
		if (FUNCTION_CANCEL == setSchedule(schedule))
		{
			return;
		}

		SQLWCHAR saleInfoSql[BUFSIZ];
		swprintf_s(saleInfoSql,	L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (%d, ?, %d, %d, %d, %d);",
			schedule.date.getValue, 
			schedule.movie.code, schedule.movie.age,
			schedule.startTime,	schedule.endTime,
			schedule.screen.number);
		SQLCancel(dbHelper.getStmt(MDF_SALE_INFO));
		SQLBindParameter(dbHelper.getStmt(MDF_SALE_INFO), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
			BUFSIZ, 0, schedule.movie.title, 0, NULL);
		
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.getValue(), schedule.screen.number, schedule.startTime, schedule.screen.number);
		
		SQLCancel(dbHelper.getStmt(MDF_SEAT));
		if (SQL_SUCCESS == SQLExecDirect(dbHelper.getStmt(MDF_SALE_INFO), saleInfoSql, SQL_NTS)
			&& SQL_SUCCESS == SQLExecDirect(dbHelper.getStmt(MDF_SEAT), seatSql, SQL_NTS))
		{
			cout << "스케쥴이 등록 되었습니다.\n";
		}
		else
		{
			cout << "스케쥴 등록을 실패했습니다.\n";
		}
		system("pause");
	}
}