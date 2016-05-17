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
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n\n"

			"1. 가격 정보 확인/삭제\n"
			"2. 가격 정보 추가\n"
			"0. 종료\n\n"

			"선택: ";
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
			cout << "\n잘못된 입력입니다.";
			system("pause");
		}
	}
}