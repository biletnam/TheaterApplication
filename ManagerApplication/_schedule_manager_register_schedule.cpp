#include "schedule_manager.h"
#include <vector>

enum {
	SCHEDULE_REGISTER = 1,
	SCREEN_SETTING = 2,
	DATE_SETTING = 3,
	MOVIE_SETTING = 4,
	TIME_SETTING = 5,
};

void ScheduleManager::registerSchedule()
{
	for (vector<Schedule> scheduleVector;;)
	{
		Schedule schedule(dbHelper);
		int16_t choice;
		do
		{
			system("cls");
			cout << "스케쥴 등록\n\n";
			cout << "등록한 스케쥴\n\n";
			for (uint16_t i = 0; i < scheduleVector.size(); i++)
			{
				scheduleVector.at(i).showInfo();
			}

			cout << "새 스케쥴\n";
			schedule.showInfo();

			cout <<
				"1. 등록\n"
				"2. 상영관 설정\n"
				"3. 날짜 설정\n"
				"4. 영화 설정\n"
				"5. 시간 설정\n"
				"0. 종료\n";
			cin >> choice;

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
			SQLCancel(dbHelper.theaterStmt);
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
		SQLBindParameter(dbHelper.saleInfoStmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
			BUFSIZ, 0, schedule.movie.title, 0, NULL);
		
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.value, schedule.screen.number, schedule.startTime, schedule.screen.number);

		if (SQLExecDirect(dbHelper.saleInfoStmt, saleInfoSql, SQL_NTS) == SQL_SUCCESS
			&& SQLExecDirect(dbHelper.seatStmt, seatSql, SQL_NTS) == SQL_SUCCESS)
		{
			scheduleVector.push_back(schedule);
		}
		else
		{
			cout << "스케쥴 등록을 실패했습니다.\n";
		}

		SQLCancel(dbHelper.saleInfoStmt);
		SQLCancel(dbHelper.seatStmt);
	}
}