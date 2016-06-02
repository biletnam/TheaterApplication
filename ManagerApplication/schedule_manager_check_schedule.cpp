#include "schedule_manager.h"

void ScheduleManager::checkAndModifySchedule()
{
	for (Schedule schedule;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 확인 / 수정\n";

		if (0 != schedule.screen.getNumber()
			|| 0 != schedule.date.getValue())
		{
			cout << "\n상영 일정 정보\n";
			schedule.show();
		}
				
		if (0 == schedule.date.getValue())
		{
			cout << "\n상영일 선택";
			Date::getToday().bindParameter();
			schedule.date.bindCol();
			schedule.date.prepare(L"SELECT date FROM date WHERE date_value>?;");
			switch (schedule.date.choose())
			{
			case FUNCTION_NULL:
				cout << "\n등록된 상영 예정일이 없습니다.\n";
				system("pause");
			case FUNCTION_CANCEL:
			case FUNCTION_ERROR:
				return;
			}
			continue;
		}
		else if (0 == schedule.screen.getNumber())
		{
			cout << "\n상영관 선택\n";
			schedule.screen.bindCol(MDF_THEATER, SCREEN_NUMBER);
			schedule.prepare(MDF_THEATER, L"SELECT number FROM screen;");
			switch (schedule.choose(MDF_THEATER))
			{
			case FUNCTION_NULL:
				cout << "\n등록된 가격 정보가 없습니다.\n";
				system("pause");
				return;
			case FUNCTION_CANCEL:
				schedule.date.initialize();
			}
			continue;
		}

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT id, movie_code, movie_title, age, start_time, end_time "
			"FROM d%d "
			"WHERE screen=%d "
			"ORDER BY start_time ASC;",
			schedule.date.getValue(), schedule.screen.getNumber());
		schedule.bindCol();
		schedule.prepare(MDF_SCHEDULE, sql);
		switch (schedule.choose(MDF_SCHEDULE))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			modifySchedule(schedule);
			break;
		case FUNCTION_NULL:
			cout << "등록된 상영 일정이 없습니다\n";
			system("pause");
		case FUNCTION_ERROR:
			break;
		}
	}
}