#include "price_manager.h"

PriceManager::PriceManager(DBHelper &dbHelper) : dbHelper(dbHelper)
{
	enum PriceManagerFunction
	{
		CHECK_N_DELETE_PRICE = 1,
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
		
		switch (inputInteger())
		{
		case CHECK_N_DELETE_PRICE:
			checkAndDeletePrice();
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