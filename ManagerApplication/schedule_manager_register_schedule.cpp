#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	enum ScheduleManagerFunction
	{
		SET_SCREEN = 1,
		SET_DATE,
		SET_MOVIE,
		SET_TIME,
		REGISTER_SCHEDULE,
	};

	for (Schedule schedule;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 등록\n"
			"\n";

		if (0 != schedule.screen.getNumber()
			|| 0 != schedule.date.getValue()
			|| 0 != schedule.movie.getCode()
			|| 0 != schedule.getStartTime())
		{
			cout << "새 스케쥴\n";
			schedule.show();
			cout << endl;
		}

		cout <<
			"1. 상영관 설정\n"
			"2. 날짜 설정\n"
			"3. 영화 설정\n"
			"4. 시간 설정\n"
			"5. 새 스케쥴 등록\n"
			"0. 종료\n"
			"\n"
			"선택: ";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_ERROR:
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
			continue;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case SET_SCREEN:
				setScreen(schedule.screen);
				continue;
			case SET_DATE:
				setDate(schedule.date);
				continue;
			case SET_MOVIE:
				setMovie(schedule.movie);
				continue;
			case SET_TIME:
				cout << endl;
				if (0 == schedule.screen.getNumber())
				{
					cout << "상영관을 선택하지 않았습니다.\n";
				}
				else if (0 == schedule.date.getValue())
				{
					cout << "상영일을 선택하지 않았습니다.\n";
				}
				else if (0 == schedule.movie.getCode())
				{
					cout << "영화를 선택하지 않았습니다.\n";
				}
				else
				{
					setTime(schedule);
					continue;
				}
				system("pause");
				continue;
			case REGISTER_SCHEDULE:
				if (0 == schedule.getStartTime())
				{
					cout << "상영 시간을 입력하지 않았습니다.\n";
					system("pause");
					continue;
				}
			}
		}

		SQLWCHAR scheduleSql[BUFSIZ];
		swprintf_s(scheduleSql, L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (?, ?, ?, ?, ?, ?);",
			schedule.date.getValue());
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.getValue(), schedule.screen.getNumber(), schedule.getStartTime(),
			schedule.screen.getNumber());

		if (SQL_SUCCESS == schedule.bindParameter()
			&& SQL_SUCCESS == schedule.execute(MDF_SCHEDULE, scheduleSql)
			&& SQL_SUCCESS == schedule.execute(MDF_SEAT, seatSql))
		{
			schedule.initialize();
			cout << "상영 일정이 등록 되었습니다.\n";
		}
		else
		{
			cout << "상영 일정 등록을 실패했습니다.\n";
		}
		system("pause");
	}
}
