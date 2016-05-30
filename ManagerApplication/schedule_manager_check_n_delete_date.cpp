#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	Date date(dbHelper);

	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 확인/삭제\n"
			"\n";

		if (0 != date.getValue())
		{

		}
		
		Date::today(dbHelper).bindParameter();
		if (SQL_SUCCESS != dbHelper.execute(MDF_THEATER, L"SELECT date FROM schedule WHERE date>?;"))
		{
			cout << "\n오류가 발생했습니다(checkSchedule).\n";
			system("pause");
			return;
		}

		switch (date.showSelectResult())
		{
		case FUNCTION_SUCCESS:
			cout <<
				"0. 종료\n"
				"\n"
				"삭제할 상영일을 선택하세요: ";
			switch (dbHelper.moveCursor(MDF_THEATER))
			{
			case FUNCTION_ERROR:
				cout << "\n오류가 발생했습니다(checkAndDeletedate).\n";
				system("pause");
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
				cout << "\n삭제되었습니다.\n";
				system("pause");
			}
		case FUNCTION_ERROR:
		case FUNCTION_NULL:
		default:
			break;
		}

/*		for (size_t i = 1;; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				date.show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록된 상영일이 없습니다\n";
				}
				else
				{
					cout << 
						"0. 종료\n"
						"\n"
						"삭제할 상영일을 선택하세요: ";
					switch (dbHelper.moveCursor(MDF_THEATER))
					{
					case FUNCTION_ERROR:
						cout << "\n오류가 발생했습니다(checkSchedule).\n";
						system("pause");
					case FUNCTION_CANCEL:
						return;
					case FUNCTION_SUCCESS:
						cout << "\n삭제되었습니다.\n";
						system("pause");
					}
				}
			}
			break;
		}*/
	}
}