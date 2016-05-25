#include "movie_manager.h"

MovieManager::MovieManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
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

		switch (inputInteger())
		{
		case DELETE_MOVIE:
			manageMovie(DELETE_MOVIE);
			break;
		case REGISTER_MOVIE:
			manageMovie(REGISTER_MOVIE);
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "잘못된 입력입니다.\n";
			system("pause");
		}
	}
}
