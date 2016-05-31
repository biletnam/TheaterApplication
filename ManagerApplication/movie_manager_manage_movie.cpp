#include "movie_manager.h"

void MovieManager::manageMovie(MovieManagerFunction function)
{
	Movie movie;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n";
		cout << ((CHECK_N_DELETE_MOVIE == function) ? 
		"  > 등록한 영화 확인 / 삭제\n" : "  > 새로운 영화 등록\n");
		cout << endl;

		if (movie.getCode() != 0)
		{
			cout << "선택한 영화 정보:\n";
			movie.show();
			switch (((CHECK_N_DELETE_MOVIE == function) ?
				movie.modify(MODIFY_DELETE) : movie.modify(MODIFY_INSERT)))
			{
			case FUNCTION_SUCCESS:
			case FUNCTION_CANCEL:
				movie.initialize();
			}
		}
		else
		{
			switch (movie.search(
				((CHECK_N_DELETE_MOVIE == function) ? MOVIE_TABLE_INTERNAL : MOVIE_TABLE_EXTERNAL)))
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