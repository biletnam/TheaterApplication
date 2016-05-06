#include "movie_manager.h"

void MovieManager::checkRegistration()
{
	for (;;)
	{	
		system("cls");
		SQLWCHAR keyword[BUFSIZ];
		Movie movie;
		movie.setKeyword(keyword, "\n검색할 영화 제목을 입력하세요");
		if (wcscmp(keyword, L"%0%") == 0)
		{
			return;
		}

		SQLHSTMT &stmt = dbHelper.theaterStmt;
		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, keyword, 0, NULL);
		SQLPrepare(stmt, L""
		"SELECT movie_code, title, director, age, year, running_time "
		"FROM Movie_internal WHERE title LIKE ?;", SQL_NTS);
		
		movie.showInfo(stmt);
		SQLCancel(stmt);
	}
}