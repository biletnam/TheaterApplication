#include "schedule.h"

FNRETURN Schedule::chooseDate()
{
	cout << "날짜 선택\n";

	//Date today = Date::getToday();
	Date today;
	today.setValue(1);
	
	SQLHSTMT &stmt = getStmt(MDF_THEATER);
	SQLCancel(stmt);
	today.bindParameter();
	date.bindParameter();
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT date FROM schedule WHERE date > ?;", SQL_NTS);
	
	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". ";
			date.show();
			cout << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "선택 가능한 날이 없습니다\n";
				system("pause");
				return FUNCTION_NULL;
			}
			else
			{
				date.setValue(0);
				cout << 
					"0. 종료\n"
					"\n"
					"선택: ";
				return moveCursor(MDF_THEATER);
			}
		}
	}

	cout << "오류가 발생했습니다..\n";
	system("pause");
	return FUNCTION_ERROR;
}