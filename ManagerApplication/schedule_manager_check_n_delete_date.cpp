#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 확인/삭제\n";

		if (0 < date.getValue())
		{
			cout << "\n선택한 날짜 정보:\n";
			date.show();

			cout << "\n삭제하시겠습니까?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				date.bindParameter();
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"DROP TABLE d%d;", date.getValue());
				if (SQL_SUCCESS == date.execute(MDF_THEATER, L"DELETE FROM schedule WHERE date=?;")
					&& SQL_SUCCESS == date.execute(MDF_SCHEDULE, sql)
					&& SQL_SUCCESS == date.execute(MDF_PRICE, sql)
					&& SQL_SUCCESS == date.execute(MDF_SALE_RECORD, sql))
				{
					cout << "\n삭제되었습니다.\n";
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(checkAndDeleteDate)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else
		{
			Date::getToday().bindParameter();
			if (SQL_SUCCESS != date.prepare(L"SELECT date FROM date WHERE date_value>?;"))
			{
				cout << "\n오류가 발생했습니다(checkSchedule).\n";
				system("pause");
				return;
			}

			date.bindCol();
			switch (date.choose())
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "등록된 상영 예정일이 없습니다\n";
				system("pause");
			}
		}
	}
}