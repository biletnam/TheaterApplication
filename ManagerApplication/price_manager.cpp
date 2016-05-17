#include "price_manager.h"

enum
{
	CHECK_PRICE_INFO = 1,
	ADD_PRICE_INFO = 2,
};

PriceManager::PriceManager(DBHelper &dbHelper)
{
	this->dbHelper = dbHelper;

	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ���� ���� ����\n\n"

			"1. ���� ���� Ȯ��/����\n"
			"2. ���� ���� �߰�\n"
			"0. ����\n\n"

			"����: ";
		int16_t choice;
		cin >> choice;

		switch (choice)
		{
		case CHECK_PRICE_INFO:
			checkPrice();
			break;
		case ADD_PRICE_INFO:
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n�߸��� �Է��Դϴ�.";
			system("pause");
		}
	}
}