#include "movie_manager.h"

void MovieManager::registerMovie()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n"
			"  > 새로운 영화 등록\n\n";

		Movie movie(dbHelper);
		switch (movie.search(MOVIE_TABLE_EXTERNAL))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			cout <<
				"0. 취소\n"
				"\n"
				"선택: ";
			switch (dbHelper.moveCursor(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
				continue;
			case FUNCTION_SUCCESS:
				if (SQL_SUCCESS == movie.bindParameter(MDF_THEATER, MOVIE_CODE)
					&& SQL_SUCCESS == dbHelper.execute(MDF_THEATER, L""
						"INSERT INTO "
						"movie_internal (movie_code, title, director, age, year, running_time) "
						"SELECT movie_code, title, director, age, year, running_time "
						"FROM movie_external WHERE movie_code=?;"))
				{
					cout << "\n등록되었습니다.\n";
				}
				else
				{
					cout << "\n오류가 발생했습니다.(registerMovie)\n";
				}
			}
		}
		system("pause");
	}
}