#include "movie_manager.h"

void MovieManager::registerMovie()
{
	for (;;)
	{
		system("cls");
		SQLWCHAR keyword[BUFSIZ];
		Movie movie;
		movie.setKeyword(keyword, "\n추가할 영화의 제목을 검색하세요");

		if (wcscmp(keyword, L"%0%") == 0)
		{
			return;
		}

		SQLHSTMT& stmt = dbHelper.theaterStmt;
		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, keyword, 0, NULL);
		SQLPrepare(stmt, L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_external WHERE title LIKE ?;",
			SQL_NTS);
				
		if (movie.showInfo(stmt) == FUNCTION_SUCCESS
			&& dbHelper.moveCursor(stmt, "영화를 선택하세요") == FUNCTION_SUCCESS
			&& SQLFreeStmt(stmt, SQL_UNBIND) == SQL_SUCCESS)
		{
			SQLINTEGER movieCode;
			SQLGetData(stmt, 1, SQL_INTEGER, &movieCode, sizeof(movieCode), NULL);
			SQLCancel(stmt);

			SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
				sizeof(movieCode), 0, &movieCode, 0, NULL);
			SQLExecDirect(stmt, L""
				"INSERT INTO "
				"movie_internal (movie_code, title, director, age, year, running_time) "
				"SELECT movie_code, title, director, age, year, running_time "
				"FROM movie_external WHERE movie_code = ?;", SQL_NTS);
		}
		SQLCancel(stmt);
	}
}

