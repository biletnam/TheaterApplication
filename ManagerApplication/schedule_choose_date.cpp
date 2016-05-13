#include "schedule.h"
#include <time.h>

int16_t Schedule::chooseDate()
{
	cout << "날짜 선택\n";

	SQLINTEGER today = date.getToday();
	today = 1;
	
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_C_LONG,
		sizeof(today), 0, &today, 0, NULL);
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
				cout << "등록 가능한 날이 없습니다\n";
				return FUNCTION_NULL;
			}
			else 
			{
				switch (dbHelper.moveCursor(stmt, "\n날짜를 선택하세요"))
				{
				case FUNCTION_SUCCESS:
					return FUNCTION_SUCCESS;
				case FUNCTION_CANCEL:
					return FUNCTION_CANCEL;
				case FUNCTION_ERROR:
					return FUNCTION_ERROR;
				}
			}
			break;
		default:
			cout << "오류가 발생했습니다.\n";
			return FUNCTION_ERROR;
		}
	}

	return FUNCTION_ERROR;
}