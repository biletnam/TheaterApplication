#include "movie_manager.h"

enum 
{
	CHOICE_CHECK = 1,
	CHOICE_REGISTER = 2,
	CHOICE_DELETE = 3,
};

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
		case CHOICE_CHECK:
			deleteMovie();
			break;
		case CHOICE_REGISTER:
			registerMovie();
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "잘못된 입력입니다.\n";
			system("pause");
		}
	}
}
