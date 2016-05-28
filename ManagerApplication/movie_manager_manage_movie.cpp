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

		str[TITLE] = "  > ���ο� ��ȭ ���\n\n";
		str[MOVE_CURSOR] = "\n�߰��� ��ȭ�� �����ϼ���: ";
		str[SQL_EXECUTE_SUCCESS] = "\n�߰��Ǿ����ϴ�.\n";
		str[SQL_EXECUTE_ERROR] = "\n�̹� ��ϵ� ��ȭ�Դϴ�.\n";

		query = L""
			"INSERT INTO "
			"movie_internal (movie_code, title, director, age, year, running_time) "
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_external WHERE movie_code = ?;";
		break;
	case DELETE_MOVIE:
		movieTable = MOVIE_TABLE_INTERNAL;
		str[TITLE] = "  > ����� ��ȭ Ȯ�� / ����\n\n";
		str[MOVE_CURSOR] = "\n������ ��ȭ�� �����ϼ���: ";
		str[SQL_EXECUTE_SUCCESS] = "\n�����Ǿ����ϴ�.\n";
		str[SQL_EXECUTE_ERROR] = "\n�̹� ������ ��ȭ�Դϴ�.\n";

		query = L"DELETE FROM movie_internal WHERE movie_code=?;";
	}
	
	for (;;)
	{
		system("cls");
		cout << 
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
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
				"0. ���\n"
				"\n"
				"����: ";
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