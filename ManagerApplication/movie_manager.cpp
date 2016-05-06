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
		cout << "��ȭ ����\n"
			"�ֱ� ��ϵ� ��ȭ ���(10��)\n";
		
		Movie movie;
		movie.showInfo(stmt);
		SQLCancel(stmt);

		cout << "\n��� Ȯ��(1), ���(2), ����(3), ����(0): ";
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
			cout << "�߸��� �Է��Դϴ�.\n"
				"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
			_getch();
		}
	}
}
