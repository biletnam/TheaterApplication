#include "price_manager.h"

void PriceManager::checkAndDeletePrice()
{
	Price price;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n"
			"  > 가격 정보 확인/삭제\n";
		
		if (0 < price.getCode())
		{
			cout << "\n선택한 가격 정보:\n";
			price.show();

			cout << "\n삭제하시겠습니까?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				price.bindParameter(MDF_THEATER, PRICE_CODE);
				if (SQL_SUCCESS == price.execute(MDF_THEATER, L"DELETE FROM price WHERE code=?;"))
				{
					cout << "\n삭제되었습니다.\n";
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(PriceManager::checkAndDeletePrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else
		{
			price.bindCol(MDF_THEATER);
			if (SQL_SUCCESS != price.prepare(MDF_THEATER, L"SELECT code, name, won FROM price;"))
			{
				cout << "\n오류가 발생했습니다(PriceManager::checkAndDeletePrice).\n";
				system("pause");
				return;
			}

			price.bindCol(MDF_THEATER);
			switch (price.choose(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "등록된 가격 정보가 없습니다\n";
				system("pause");
			}
		}
	}
}


