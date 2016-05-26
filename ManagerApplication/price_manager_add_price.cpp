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

			if (0 == price.code)
			{
				switch (price.inputCode())
				{
				case FUNCTION_CANCEL:
					return;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					price.code = 0;
				}
			}
			else if (0 == *price.name)
			{
				switch (price.inputName())
				{
				case FUNCTION_CANCEL:
					price.code = 0;
					break;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					*price.name = 0;
				}
			}
			else if (0 == price.won)
			{
				switch (price.inputWon())
				{
				case FUNCTION_CANCEL:
					*price.name = 0;
					break;
				case FUNCTION_SUCCESS:
					break;
				case FUNCTION_ERROR:
					price.won = 0;
				}
			}
			else
			{
				break;
			}
		}
		
		SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);
		SQLCancel(stmt);

		dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &price.code);
		dbHelper.bindParameter(MDF_THEATER, BIND_STRING, price.name);
		dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &price.code);
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