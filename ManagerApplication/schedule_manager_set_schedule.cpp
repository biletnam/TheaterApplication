#include "schedule_manager.h"

enum ScheduleManagerFunction
{
	CHOOSE_SCREEN = 1,
	CHOOSE_DATE,
	CHOOSE_MOVIE,
	INPUT_TIME,
	REGISTER_SCHEDULE,
};

FNRETURN ScheduleManager::setSchedule(Schedule & schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 등록\n"
			"\n"
			"새 스케쥴\n";
		schedule.showInfo();

		cout <<
			"1. 상영관 설정\n"
			"2. 날짜 설정\n"
			"3. 영화 설정\n"
			"4. 시간 설정\n"
			"5. 새 스케쥴 등록\n"
			"0. 종료\n";

		int8_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return FUNCTION_CANCEL;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case FUNCTION_CANCEL:
				return FUNCTION_CANCEL;
			case CHOOSE_SCREEN:
				schedule.chooseScreen();
				continue;
			case CHOOSE_DATE:
				schedule.chooseDate();
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
					return FUNCTION_SUCCESS;
				}
				system("pause");
				continue;
			}
		case FUNCTION_ERROR:
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
		}
	}
}
