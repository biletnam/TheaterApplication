#include "movie_manager.h"

void MovieManager::manageMovie(MOVIE_MANAGER_FUNCTION function)
{
	enum charStr
	{
		TITLE,
		SET_KEYWORD,
		MOVE_CURSOR,
		SQL_EXECUTE,
		CHAR_STR_CNT,
	};
	
	enum SQLWCHARQuery
	{
		QUERY_SELECT,
		QUERY_MODIFY,
		SQLWCHAR_QUERY_CNT,
	};

	char *str[CHAR_STR_CNT];
	SQLWCHAR *query[SQLWCHAR_QUERY_CNT];

	switch (function)
	{
	case REGISTER_MOVIE:
		str[TITLE] = 
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			"  > ���ο� ��ȭ ���\n\n";
		str[SET_KEYWORD] = "�߰��� ��ȭ�� ������ �˻��ϼ���";
		str[MOVE_CURSOR] = "\n�߰��� ��ȭ�� �����ϼ���: ";
		str[SQL_EXECUTE] = "\n�̹� ��ϵ� ��ȭ�Դϴ�.\n";

		query[QUERY_SELECT] = L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_external WHERE title LIKE ?;";
		query[QUERY_MODIFY] = L""
			"INSERT INTO "
			"movie_internal (movie_code, title, director, age, year, running_time) "
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_external WHERE movie_code = ?;";
		break;
	case DELETE_MOVIE:
		str[TITLE] = 
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			"  > ����� ��ȭ Ȯ�� / ����\n\n";
		str[SET_KEYWORD] = "����� ��ȭ�� ������ �˻��ϼ���";
		str[MOVE_CURSOR] = "\n������ ��ȭ�� �����ϼ���: ";
		str[SQL_EXECUTE] = "\n�̹� ������ ��ȭ�Դϴ�.\n";

		query[QUERY_SELECT] = L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_internal WHERE title LIKE ?;";
		query[QUERY_MODIFY] = L"DELETE FROM movie_internal WHERE movie_code=?;";
		break;
	default:
		return;
	}
	
	for (;;)
	{
		system("cls");
		cout << str[TITLE];

		SQLWCHAR keyword[BUFSIZ];
		Movie movie;
		movie.setKeyword(keyword, str[SET_KEYWORD]);
		if (wcscmp(keyword, L"%0%") == 0)
		{
			return;
		}

		SQLHSTMT& stmt = dbHelper.getStmt(MDF_THEATER);
		SQLCancel(stmt);
		SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
			BUFSIZ, 0, keyword, 0, NULL);
		SQLPrepare(stmt, query[QUERY_SELECT], SQL_NTS);

		cout << endl;
		if (FUNCTION_SUCCESS == movie.show(dbHelper))
		{
			cout << "0. ���\n";
			if (FUNCTION_SUCCESS == dbHelper.moveCursor(stmt, str[MOVE_CURSOR]))
			{
				SQLFreeStmt(stmt, SQL_UNBIND);
				SQLGetData(stmt, 1, SQL_INTEGER, &movie.code, sizeof movie.code, NULL);

				SQLCancel(stmt);
				SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
					sizeof movie.code, 0, &movie.code, 0, NULL);
				if (SQL_SUCCESS != SQLExecDirect(stmt, query[QUERY_MODIFY], SQL_NTS))
				{
					cout << str[SQL_EXECUTE];
					system("pause");
				}
			}
		}
	}
}