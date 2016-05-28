#include "movie_manager.h"

void MovieManager::manageMovie(MOVIE_MANAGER_FUNCTION function)
{
	enum charStr
	{
		TITLE,
		MOVE_CURSOR,
		SQL_EXECUTE_SUCCESS,
		SQL_EXECUTE_ERROR,
		CHAR_STR_CNT,
	};
	
	char *str[CHAR_STR_CNT];
	SQLWCHAR *query;
	MovieTable movieTable;

	switch (function)
	{
	case REGISTER_MOVIE:
		movieTable = MOVIE_TABLE_EXTERNAL;

		str[TITLE] = "  > 새로운 영화 등록\n\n";
		str[MOVE_CURSOR] = "\n추가할 영화를 선택하세요: ";
		str[SQL_EXECUTE_SUCCESS] = "\n추가되었습니다.\n";
		str[SQL_EXECUTE_ERROR] = "\n이미 등록된 영화입니다.\n";

		query = L""
			"INSERT INTO "
			"movie_internal (movie_code, title, director, age, year, running_time) "
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_external WHERE movie_code = ?;";
		break;
	case DELETE_MOVIE:
		movieTable = MOVIE_TABLE_INTERNAL;
		str[TITLE] = "  > 등록한 영화 확인 / 삭제\n\n";
		str[MOVE_CURSOR] = "\n삭제할 영화를 선택하세요: ";
		str[SQL_EXECUTE_SUCCESS] = "\n삭제되었습니다.\n";
		str[SQL_EXECUTE_ERROR] = "\n이미 삭제된 영화입니다.\n";

		query = L"DELETE FROM movie_internal WHERE movie_code=?;";
	}
	
	for (;;)
	{
		system("cls");
		cout << 
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n"
			<< str[TITLE];
		
		Movie movie(dbHelper);
		switch (movie.choose(movieTable))
		{
		case FUNCTION_SUCCESS:
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_ERROR:
		}
		if (FUNCTION_SUCCESS == movie.search(movieTable))
		{
			cout << 
				"0. 취소\n"
				"\n"
				"선택: ";
			if (FUNCTION_SUCCESS == dbHelper.moveCursor(MDF_THEATER))
			{
				movie.getData(MDF_THEATER, 1, MOVIE_CODE);
				if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, query))
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