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
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n\n"

			"1. 가격 정보 확인/삭제\n"
			"2. 가격 정보 추가\n"
			"0. 종료\n\n"

			"선택: ";
		
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
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
		}
	}
}