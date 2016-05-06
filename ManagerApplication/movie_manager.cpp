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
		SQLHSTMT& stmt = dbHelper.theaterStmt;
		SQLPrepare(stmt, L""
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM Movie_internal;", 
			SQL_NTS);

		system("cls");
		cout << "영화 관리\n"
			"최근 등록된 영화 목록(10개)\n";
		
		Movie movie;
		movie.showInfo(stmt);
		SQLCancel(stmt);

		cout << "\n목록 확인(1), 등록(2), 삭제(3), 종료(0): ";
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
