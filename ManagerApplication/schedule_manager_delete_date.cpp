#include "schedule_manager.h"

void ScheduleManager::deleteDate()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 확인/삭제\n"
			"\n";

		SQLHSTMT &stmt = dbHelper.getStmt(THEATER);
		SQLCancel(stmt);
		Date date;
		SQLBindCol(stmt, 1, SQL_INTEGER, &date.value, sizeof date.value, NULL);

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L"SELECT date FROM schedule WHERE date>%d;", Date::getToday());
		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				date.show();
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록된 상영 일정이 없습니다\n";
					system("pause");
					return;
				}

				cout << "0. 종료\n";
				switch (dbHelper.moveCursor(stmt, "\n수정할 상영 일정을 선택하세요: "))
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					break;
				default:
					cout << "오류가 발생했습니다(checkSchedule).\n";
					system("pause");
				}
			}
		}
	}
}
