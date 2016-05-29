#include "price_manager.h"

void PriceManager::addPrice()
{
	for (;;)
	{
		Price price(dbHelper);

		for (;;)
		{
			system("cls");
			cout <<
				"극장 관리 시스템\n"
				" > 가격 정보 관리\n"
				"  > 가격 정보 추가\n"
				"\n"
				"새로운 가격 정보\n";
			price.show();
			cout << endl;

			if (0 == price.getCode())
			{
				switch (price.inputCode())
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					price.setCode(0);
				}
			}
			else if (0 == *price.getName())
			{
				switch (price.inputName())
				{
				case FUNCTION_CANCEL:
					price.setCode(0);
					break;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					price.setName((SQLCHAR*)"");
				}
			}
			else if (0 == price.getWon())
			{
				switch (price.inputWon())
				{
				case FUNCTION_CANCEL:
					price.setName((SQLCHAR*)"");
					break;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					price.setWon(0);
				}
			}
			else
			{
				break;
			}
		}
		
		SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);
		SQLCancel(stmt);

		price.bindParameter(MDF_THEATER, PRICE_CODE);
		price.bindParameter(MDF_THEATER, PRICE_NAME);
		price.bindParameter(MDF_THEATER, PRICE_WON);
		if (SQL_SUCCESS 
			== SQLExecDirect(stmt, L"INSERT INTO price (code, name, won) values(?, ?, ?);", SQL_NTS))
		{
			cout << "가격 정보가 추가되었습니다.\n";
		}
		else
		{
			cout << "오류가 발생했습니다.(addPrice)\n";
		}
		system("pause");
	}
}
