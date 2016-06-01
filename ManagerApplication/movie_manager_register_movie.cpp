#include "movie_manager.h"

void MovieManager::registereMovie()
{
	Movie movie;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n";
			"  > 새로운 영화 등록\n";
		cout << endl;

		if (movie.getCode() != 0)
		{
			cout << "선택한 영화 정보:\n";
			movie.show();
			cout << "\n등록하시겠습니까?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				movie.bindParameter(MDF_THEATER, MOVIE_CODE);
				if (SQL_SUCCESS == movie.execute(MDF_THEATER, L""
					"INSERT INTO "
					"movie_internal (movie_code, title, director, age, year, running_time) "
					"SELECT movie_code, title, director, age, year, running_time "
					"FROM movie_external WHERE movie_code=?;"))
				{
					cout << "\n등록되었습니다.\n";
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(registerMovie)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				movie.initialize();
			}
		}
		else
		{
			switch (movie.search(MOVIE_TABLE_EXTERNAL))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
				switch (movie.choose(MDF_THEATER))
				{
				case FUNCTION_NULL:
					cout << "등록된 영화가 없습니다.\n";
					system("pause");
				case FUNCTION_CANCEL:
				case FUNCTION_ERROR:
					movie.initialize();
				}
			}
		}
	}
}