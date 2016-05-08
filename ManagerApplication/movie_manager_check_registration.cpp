#include "movie_manager.h"

void MovieManager::checkRegistration()
{
	system("cls");
	cout << "극장 관리 시스템\n"
		" > 영화 정보 관리\n"
		"  > 등록한 영화 확인\n\n"
		"최근 등록된 영화 목록(10개)\n";

	SQLHSTMT& stmt = dbHelper.theaterStmt;
	SQLPrepare(stmt, L""
		"SELECT movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;",
		SQL_NTS);

	{
		Movie movie;
		movie.showInfo(stmt);
	}
		SQLCancel(stmt);

	for (;;)
	{	
		SQLWCHAR keyword[BUFSIZ];
		Movie movie;
		movie.setKeyword(keyword, "\n검색할 영화 제목을 입력하세요");
		if (wcscmp(keyword, L"%0%") == 0)
		{
			return;
		}

		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, keyword, 0, NULL);
		SQLPrepare(stmt, L""
		"SELECT movie_code, title, director, age, year, running_time "
		"FROM Movie_internal WHERE title LIKE ?;", SQL_NTS);
		
		movie.showInfo(stmt);
		SQLCancel(stmt);
	}
}