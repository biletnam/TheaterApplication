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
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n\n";

		showRecent();

		cout <<
			"\n--------------------------\n\n"

			"1. ����� ��ȭ Ȯ�� / ����\n"
			"2. ���ο� ��ȭ ���\n"
			"0. ����\n\n"

			"����: ";

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
			cout << "�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
