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
		cout << "���� ���� �ý���\n"
			" > ��ȭ ���� ����\n\n"
			"1. ����� ��ȭ Ȯ��\n"
			"2. ���ο� ��ȭ ���\n"
			"3. ����� ��ȭ ����\n"
			"0. ����\n\n"
			"����: ";

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
