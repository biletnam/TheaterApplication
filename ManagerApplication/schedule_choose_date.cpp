#include "schedule.h"

FNRETURN Schedule::chooseDate()
{
	cout << "날짜 선택\n";

	//Date today = Date::getToday();
	Date today(1);
	
	SQLHSTMT &stmt = dbHelper.getStmt(THEATER);
	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_C_LONG,
		sizeof today.value, 0, &today.value, 0, NULL);
	SQLBindCol(stmt, 1, SQL_INTEGER, &date.value, sizeof(date.value), NULL);
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
				date.value = 0;
				cout << "0. 종료\n";
				return dbHelper.moveCursor(stmt, "\n선택: ");
			}
		}
	}

	cout << "오류가 발생했습니다..\n";
	system("pause");
	return FUNCTION_ERROR;
}