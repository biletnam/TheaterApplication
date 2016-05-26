#include "schedule.h"

// return ����
// do while ����

FNRETURN Schedule::chooseMovie()
{
	SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);

	do
	{
		SQLWCHAR keyword[BUFSIZ];
		movie.setKeyword(keyword, "����� ��ȭ ������ �Է��ϼ���");

		if (wcscmp(keyword, L"%0%") == FUNCTION_CANCEL)
		{
			return FUNCTION_CANCEL;
		}

		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, &keyword, 0, NULL);
		SQLPrepare(stmt, L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM Movie_internal "
			"WHERE title LIKE ?;", SQL_NTS);

		if ((movie.show(dbHelper) == FUNCTION_SUCCESS)
			&& (dbHelper.moveCursor(stmt, "��ȭ�� �����ϼ���") == FUNCTION_SUCCESS))
		{
			SQLFreeStmt(stmt, SQL_UNBIND);

			SQLGetData(stmt, 1, SQL_INTEGER, &movie.code, sizeof(movie.code), NULL);
			SQLGetData(stmt, 2, SQL_CHAR, movie.title, BUFSIZ, NULL);
			SQLGetData(stmt, 3, SQL_INTEGER, &movie.age, sizeof(movie.age), NULL);
			return FUNCTION_SUCCESS;
		}
	} while (true);
		
	return FUNCTION_ERROR;
}