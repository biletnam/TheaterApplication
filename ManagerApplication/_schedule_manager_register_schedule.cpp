#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	enum ScheduleManagerFunction
	{
		SCHEDULE_REGISTER = 1,
		SCREEN_SETTING = 2,
		DATE_SETTING = 3,
		MOVIE_SETTING = 4,
		TIME_SETTING = 5,
	};

	for (;;)
	{
		Schedule schedule(dbHelper);
		FNRETURN choice;
		do
		{
			system("cls");
			cout << "스케쥴 등록\n\n"
				"등록한 스케쥴\n\n";

			cout << "새 스케쥴\n";
			schedule.showInfo();

			cout <<
				"1. 등록\n"
				"2. 상영관 설정\n"
				"3. 날짜 설정\n"
				"4. 영화 설정\n"
				"5. 시간 설정\n"
				"0. 종료\n";

			choice = inputInteger();
			switch (choice)
			{
			case SCREEN_SETTING:
				schedule.chooseScreen();
			case DATE_SETTING:
				schedule.chooseDate();
				break;
			case MOVIE_SETTING:
				schedule.chooseMovie();
				break;
			case TIME_SETTING:
				schedule.inputTime();
				break;
			case FUNCTION_CANCEL:
				return;
			}
			SQLCancel(dbHelper.getStmt(THEATER));
		} while (choice != SCHEDULE_REGISTER);

		SQLWCHAR saleInfoSql[BUFSIZ];
		swprintf_s(saleInfoSql,	L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (%d, ?, %d, %d, %d, %d);",
			schedule.date.value, 
			schedule.movie.code, schedule.movie.age,
			schedule.startTime,	schedule.endTime,
			schedule.screen.number);
		SQLBindParameter(dbHelper.getStmt(SALE_INFO), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
			BUFSIZ, 0, schedule.movie.title, 0, NULL);
		
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.value, schedule.screen.number, schedule.startTime, schedule.screen.number);

		if (SQLExecDirect(dbHelper.getStmt(SALE_INFO), saleInfoSql, SQL_NTS) == SQL_SUCCESS
			&& SQLExecDirect(dbHelper.getStmt(SEAT), seatSql, SQL_NTS) == SQL_SUCCESS)
		{
		}
		else
		{
			cout << "스케쥴 등록을 실패했습니다.\n";
		}

		SQLCancel(dbHelper.getStmt(SALE_INFO));
		SQLCancel(dbHelper.getStmt(SEAT));
	}
}