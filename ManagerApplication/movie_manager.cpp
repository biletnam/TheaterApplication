#include "movie_manager.h"

MovieManager::MovieManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum movieManagerFunction
	{
		CHECK_N_DELETE_MOVIE = 1,
		REGISTER_MOVIE,
	} typedef MOVIE_MANAGER_FUNCTION;

	for (;;)
	{
		system("cls");
		cout << 
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n\n";

		showRecent();

		cout <<
			"\n--------------------------\n\n"

			"1. 등록한 영화 확인 / 삭제\n"
			"2. 새로운 영화 등록\n"
			"0. 종료\n\n"

			"선택: ";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case CHECK_N_DELETE_MOVIE:
				checkAndDeleteMovie();
				continue;
			case REGISTER_MOVIE:
				registerMovie();
				continue;
			}
		case FUNCTION_ERROR:
			cout << "잘못된 입력입니다.\n";
			system("pause");
		}
		
	}
}
