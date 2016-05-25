#include "movie_manager.h"

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
		case DELETE_MOVIE:
			manageMovie(DELETE_MOVIE);
			break;
		case REGISTER_MOVIE:
			manageMovie(REGISTER_MOVIE);
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
