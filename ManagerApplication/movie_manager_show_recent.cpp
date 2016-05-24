#include "movie_manager.h"

void MovieManager::showRecent()
{
	cout << "�ֱ� ��ϵ� ��ȭ ���(10��)\n";

	SQLHSTMT& stmt = dbHelper.getStmt(THEATER);
	SQLPrepare(stmt, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;",
		SQL_NTS);

	Movie movie;
	movie.showInfo(stmt);

	SQLCancel(stmt);
}
