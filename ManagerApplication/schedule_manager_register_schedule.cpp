#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	enum ScheduleManagerFunction
	{
		CHOOSE_SCREEN = 1,
		CHOOSE_DATE,
		CHOOSE_MOVIE,
		INPUT_TIME,
		REGISTER_SCHEDULE,
	};

	Schedule schedule;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 등록\n"
			"\n"
			"새 스케쥴\n";
		schedule.show();

		cout <<
			"1. 상영관 설정\n"
			"2. 날짜 설정\n"
			"3. 영화 설정\n"
			"4. 시간 설정\n"
			"5. 새 스케쥴 등록\n"
			"0. 종료\n";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case CHOOSE_SCREEN:
				schedule.chooseScreen();
				continue;
			case CHOOSE_DATE:
				schedule.date.choose();
				continue;
			case CHOOSE_MOVIE:
				schedule.chooseMovie();
				continue;
			case INPUT_TIME:
				schedule.inputTime();
				continue;
			case REGISTER_SCHEDULE:
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
				else if (schedule.time.getStartTime() == 0)
				{
					cout << "상영 시간을 입력하지 않았습니다.\n";
				}
				else
				{
					break;;
				}
				system("pause");
				continue;
			}
			break;
		case FUNCTION_ERROR:
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
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