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
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n"
			"  > 새로운 영화 등록\n\n";
		str[SET_KEYWORD] = "추가할 영화의 제목을 검색하세요";
		str[MOVE_CURSOR] = "\n추가할 영화를 선택하세요: ";
		str[SQL_EXECUTE] = "\n이미 등록된 영화입니다.\n";

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
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n"
			"  > 등록한 영화 확인 / 삭제\n\n";
		str[SET_KEYWORD] = "등록한 영화의 제목을 검색하세요";
		str[MOVE_CURSOR] = "\n삭제할 영화를 선택하세요: ";
		str[SQL_EXECUTE] = "\n이미 삭제된 영화입니다.\n";

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
			cout << "0. 취소\n";
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