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


		if (0 != schedule.date.getValue())
		{
			cout << "\n상영 일정 정보\n";
			schedule.date.show();
		}
		if (0 != schedule.screen.getNumber())
		{
			schedule.screen.show();
		}
				
		if (0 == schedule.date.getValue())
		{
			cout << "\n상영일 선택";
			if (SQL_SUCCESS != Date::getToday().bindParameter()
				|| SQL_SUCCESS != schedule.date.bindCol()
				|| SQL_SUCCESS != schedule.prepare(MDF_THEATER, 
					L"SELECT date_value FROM date WHERE date_value>?;"))
			{
				cout << "\n오류가 발생했습니다.(checkAndDeleteDate)\n";
				system("pause");
				return;
			}

			switch (schedule.date.choose(MDF_THEATER))
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
			cout << "\n상영관 선택";
			if (SQL_SUCCESS != schedule.screen.bindCol()
				|| SQL_SUCCESS != schedule.prepare(MDF_THEATER, L"SELECT number, row, col FROM screen;"))
			{
				cout << "\n오류가 발생했습니다.(checkAndDeleteDate)\n";
				system("pause");
				return;
			}

			switch (schedule.screen.choose(MDF_THEATER))
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

		if (SQL_SUCCESS != schedule.bindCol()
			|| SQL_SUCCESS != schedule.prepare(MDF_SCHEDULE, sql))
		{
			cout << "\n오류가 발생했습니다.(checkAndDeleteDate)\n";
			system("pause");
			return;
		}

		switch (schedule.choose(MDF_SCHEDULE))
		{
		case FUNCTION_ERROR:
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_NULL:
			cout << "등록된 상영 일정이 없습니다\n";
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			modifySchedule(schedule);
		}
	}
}