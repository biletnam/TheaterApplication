#include "schedule_manager.h"

void ScheduleManager::deleteSchedule(Schedule &schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 확인/수정\n"
			"   > 상영 일정 삭제\n"
			"\n"
			"선택한 상영 일정\n";
		schedule.show();

		cout << "\n삭제하시겠습니까?(y/n): ";
		switch (inputYN())
		{
		case FUNCTION_ERROR:
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			SQLWCHAR scheduleSql[BUFSIZ];	// + priceSql
			swprintf_s(scheduleSql,	L"DELETE FROM d%d WHERE id=%d;",
				schedule.date.getValue(), schedule.getId());

			SQLWCHAR seatSql[BUFSIZ];
			swprintf_s(seatSql, L"DROP TABLE d%ds%d;", schedule.date.getValue(), schedule.getId());

			// return 값 확인해야 함
			if (SQL_SUCCESS == schedule.execute(MDF_SCHEDULE, scheduleSql)
				&& SQL_SUCCESS == schedule.execute(MDF_PRICE, scheduleSql)
				&& SQL_SUCCESS == schedule.execute(MDF_SEAT, seatSql))
			{
				cout << "\n삭제되었습니다.\n";
				system("pause");
			}
			else
			{
				cout << "\n오류가 발생했습니다.(deleteSchedule)\n";
				system("pause");
				break;
			}
		case FUNCTION_CANCEL:
			return;
		}

	}
}