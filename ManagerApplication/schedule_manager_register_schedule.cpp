#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	for (;;)
	{
		Schedule schedule;
		if (FUNCTION_CANCEL == setSchedule(schedule))
		{
			return;
		}

		SQLWCHAR saleInfoSql[BUFSIZ];

		swprintf_s(saleInfoSql, L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (?, ?, ?, ?, ?, ?);",
			schedule.date.getValue());
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_TITLE);
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_AGE);
		schedule.time.bindParameter(MDF_SALE_INFO, START_TIME);
		schedule.time.bindParameter(MDF_SALE_INFO, END_TIME);
		schedule.screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);
		
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.getValue(), schedule.screen.getNumber(), schedule.time.getStartTime(), 
			schedule.screen.getNumber());
		
		if (SQL_SUCCESS == schedule.execute(MDF_SALE_INFO, saleInfoSql)
			&& SQL_SUCCESS == schedule.execute(MDF_SEAT, seatSql))
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