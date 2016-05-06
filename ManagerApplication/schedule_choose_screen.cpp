#include "schedule.h"
#include <conio.h>

int16_t Schedule::chooseScreen()
{
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	SQLBindCol(stmt, 1, SQL_INTEGER, &screen.number, sizeof(screen.number), NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT number FROM screen;", SQL_NTS);

	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". 스크린" << screen.number << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "등록 가능한 상영관이 없습니다\n";
				return FUNCTION_NULL;
			}
			else
			{
				switch (dbHelper.moveCursor(stmt, "\n상영관을 선택하세요"))
				{
				case FUNCTION_SUCCESS:
					return FUNCTION_SUCCESS;
				case FUNCTION_CANCEL:
					return FUNCTION_CANCEL;
				case FUNCTION_ERROR:
					return FUNCTION_ERROR;
				}
			}
		default:
			cout << "오류가 발생했습니다.\n";
			_getch();
			return FUNCTION_ERROR;
		}
	}

	return FUNCTION_ERROR;
}