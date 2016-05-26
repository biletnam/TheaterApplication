#include "movie_manager.h"

void MovieManager::manageMovie(MOVIE_MANAGER_FUNCTION function)
{
	enum charStr
	{
		TITLE,
		SET_KEYWORD,
		MOVE_CURSOR,
		SQL_EXECUTE_SUCCESS,
		SQL_EXECUTE_ERROR,
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
		str[TITLE] = "  > ���ο� ��ȭ ���\n\n";
		str[SET_KEYWORD] = "�߰��� ��ȭ�� ������ �˻��ϼ���";
		str[MOVE_CURSOR] = "\n�߰��� ��ȭ�� �����ϼ���: ";
		str[SQL_EXECUTE_ERROR] = "\n�̹� ��ϵ� ��ȭ�Դϴ�.\n";

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
		str[TITLE] = "  > ����� ��ȭ Ȯ�� / ����\n\n";
		str[SET_KEYWORD] = "����� ��ȭ�� ������ �˻��ϼ���";
		str[MOVE_CURSOR] = "\n������ ��ȭ�� �����ϼ���: ";
		str[SQL_EXECUTE_ERROR] = "\n�̹� ������ ��ȭ�Դϴ�.\n";

		query[QUERY_SELECT] = L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_internal WHERE title LIKE ?;";
		query[QUERY_MODIFY] = L"DELETE FROM movie_internal WHERE movie_code=?;";
	}
	
	for (;;)
	{
		system("cls");
		cout << 
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			<< str[TITLE];

		SQLWCHAR keyword[BUFSIZ];
		Movie movie;
		movie.setKeyword(keyword, str[SET_KEYWORD]);
		if (wcscmp(keyword, L"%0%") == 0)
		{
			return;
		}

		SQLHSTMT& stmt = dbHelper.getStmt(MDF_THEATER);
		dbHelper.bindParameter(MDF_THEATER, BIND_STRING, keyword);
		dbHelper.prepare(MDF_THEATER, query[QUERY_SELECT]);

		cout << endl;
		if (FUNCTION_SUCCESS == movie.show(dbHelper))
		{
			cout << "0. ���\n";
			if (FUNCTION_SUCCESS == dbHelper.moveCursor(MDF_THEATER, str[MOVE_CURSOR]))
			{
				dbHelper.getData(MDF_THEATER, 1, BIND_INTEGER, &movie.code);
				dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &movie.code);
				if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, query[QUERY_MODIFY]))
				{
					cout << str[SQL_EXECUTE_SUCCESS];
				}
				else
				{
					cout << str[SQL_EXECUTE_ERROR];
				}
				system("pause");
			}
		}
	}
}