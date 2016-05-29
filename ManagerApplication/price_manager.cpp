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
		
		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case CHECK_N_DELETE_PRICE:
				checkAndDeletePrice();
				continue;
			case ADD_PRICE_INFO:
				addPrice();
				continue;
			}
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}