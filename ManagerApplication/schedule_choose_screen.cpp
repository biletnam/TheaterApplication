#include "schedule.h"
#include <conio.h>

int16_t Schedule::chooseScreen()
{
	cout << "상영관 선택\n";
	
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	SQLCancel(stmt);
	SQLBindCol(stmt, 1, SQL_INTEGER, &screen.number, sizeof(screen.number), NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT number FROM screen;", SQL_NTS);
	
	for (int i = 1; SQL_SUCCESS == ret; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << screen.number << "관\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "등록 가능한 상영관이 없습니다\n";
				return FUNCTION_NULL;
			}
			else
			{
				return dbHelper.moveCursor(stmt, "\n상영관을 선택하세요");
			}
		}
	}
	
	cout << "오류가 발생했습니다.\n";
	_getch();
	return FUNCTION_ERROR;
}