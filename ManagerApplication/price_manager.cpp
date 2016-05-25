#include "price_manager.h"

PriceManager::PriceManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum PriceManagerFunction
	{
		CHECK_PRICE_INFO = 1,
		ADD_PRICE_INFO,
	};

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
			addPrice();
			break;
		case FUNCTION_CANCEL:
			return;
		default:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}