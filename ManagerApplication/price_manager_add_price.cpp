#include "price_manager.h"

void PriceManager::addPrice()
{
	Price price;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n"
			"  > 가격 정보 추가\n"
			"\n";

		if (0 < price.getCode())
		{
			cout << "새로운 가격 정보\n"
				<< "가격 코드: " << price.getCode() << endl;
			if (0 != *price.getName())
			{
				wcout << L"가격 이름: " << price.getName() << endl;
				if (-1 < price.getWon())
				{
					cout << "가격: " << price.getWon() << "원\n";
				}
			}
			cout << endl;
		}

		if (0 < price.getCode()
			&& 0 != *price.getName()
			&& -1 < price.getWon())
		{
			cout << "추가하시겠습니까?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				price.bindParameter(MDF_THEATER, PRICE_CODE);
				price.bindParameter(MDF_THEATER, PRICE_NAME);
				price.bindParameter(MDF_THEATER, PRICE_WON);
				if (SQL_SUCCESS	== price.execute(MDF_THEATER, 
					L"INSERT INTO price (code, name, won) values(?, ?, ?);"))
				{
					cout << "\n추가되었습니다.\n";
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(addPrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else if (FUNCTION_CANCEL == price.input())
		{
			return;
		}
	}
}
