#include "movie_manager.h"

void MovieManager::deleteMovie()
{
	for (;;)
	{
		system("cls");
		SQLWCHAR keyword[BUFSIZ];
		Movie movie;
		movie.setKeyword(keyword, "������ ��ȭ�� ������ �˻��ϼ���");
		if (wcscmp(keyword, L"%0%") == 0)
		{
			break;
		}

		SQLHSTMT& stmt = dbHelper.theaterStmt;
		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, keyword, 0, NULL);
		SQLPrepare(stmt, L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_internal WHERE title LIKE ?;",
			SQL_NTS);
		movie.showInfo(stmt);
		SQLFreeStmt(stmt, SQL_UNBIND);

		if (dbHelper.moveCursor(stmt, "��ȭ�� �����ϼ���") == true)
		{
			SQLINTEGER movieCode;
			SQLGetData(stmt, 1, SQL_INTEGER, &movieCode, sizeof(movieCode), NULL);
			SQLCancel(stmt);

			SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
				sizeof(movieCode), 0, &movieCode, 0, NULL);
			SQLExecDirect(stmt,
				L"DELETE FROM movie_internal WHERE movie_code=?;", SQL_NTS);
		}
		SQLCancel(stmt);
	}
}

