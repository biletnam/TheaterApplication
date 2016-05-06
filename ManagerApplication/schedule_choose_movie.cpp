#include "schedule.h"

int16_t Schedule::chooseMovie()
{
	int16_t returnValue;
	SQLHSTMT &stmt = dbHelper.theaterStmt;

	do
	{
		SQLWCHAR keyword[BUFSIZ];
		movie.setKeyword(keyword, "등록할 영화 제목을 입력하세요");

		if (wcscmp(keyword, L"%0%") == FUNCTION_CANCEL)
		{
			returnValue = FUNCTION_CANCEL;
			break;
		}

		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, &keyword, 0, NULL);
		SQLPrepare(stmt, L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM Movie_internal "
			"WHERE title LIKE ?;", SQL_NTS);

		if ((movie.showInfo(stmt) == true)
			&& (dbHelper.moveCursor(stmt, "영화를 선택하세요") == true))
		{
			SQLGetData(stmt, 1, SQL_INTEGER, &movie.code, sizeof(movie.code), NULL);
			SQLGetData(stmt, 2, SQL_CHAR, movie.title, BUFSIZ, NULL);
			SQLGetData(stmt, 3, SQL_INTEGER, &movie.age, sizeof(movie.age), NULL);
			returnValue = true;
		}
	} while (true);
		
	return returnValue;
}