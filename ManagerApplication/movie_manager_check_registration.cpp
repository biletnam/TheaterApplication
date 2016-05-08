#include "movie_manager.h"

void MovieManager::checkRegistration()
{
	system("cls");
	cout << "���� ���� �ý���\n"
		" > ��ȭ ���� ����\n"
		"  > ����� ��ȭ Ȯ��\n\n"
		"�ֱ� ��ϵ� ��ȭ ���(10��)\n";

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
		movie.setKeyword(keyword, "\n�˻��� ��ȭ ������ �Է��ϼ���");
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