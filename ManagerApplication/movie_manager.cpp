#include "movie_manager.h"

enum 
{
	CHOICE_CHECK = 1,
	CHOICE_REGISTER = 2,
	CHOICE_DELETE = 3,
};

MovieManager::MovieManager(DBHelper& dbHelper)
{
	this->dbHelper = dbHelper;

	for (;;)
	{
		system("cls");
		cout << "극장 관리 시스템\n"
			" > 영화 정보 관리\n\n"
			"1. 등록한 영화 확인\n"
			"2. 새로운 영화 등록\n"
			"3. 등록한 영화 삭제\n"
			"0. 종료\n\n"
			"선택: ";

		int16_t choice;
		cin >> choice;

		switch (choice)
		{
		case CHOICE_CHECK:
			checkRegistration();
			break;
		case CHOICE_REGISTER:
			registerMovie();
			break;
		case CHOICE_DELETE:
			deleteMovie();
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cin.clear();
			cin.ignore(100, '\n');
			cout << "잘못된 입력입니다.\n"
				"계속하려면 아무 키나 누르십시오...";
			_getch();
		}
	}
}
