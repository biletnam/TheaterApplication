#include "price_manager.h"

void PriceManager::checkAndDeletePrice()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n"
			"  > 가격 정보 확인/삭제\n\n";

		Price price(dbHelper);
		SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);
		SQLCancel(stmt);
		price.bindCol(stmt);
		SQLRETURN ret = SQLExecDirect(stmt, L"SELECT code, name, won FROM price;", SQL_NTS);

		for (size_t i = 1; SQL_SUCCESS == ret; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				price.show();
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록된 가격 정보가 없습니다.\n";
					system("pause");
					return;
				}
				else
				{
					cout << 
						"0. 종료\n"
						"\n"
						"삭제할 가격 정보를 선택하세요: ";

					switch (dbHelper.moveCursor(MDF_THEATER))
					{
					case FUNCTION_CANCEL:
						return;
					case FUNCTION_SUCCESS:
						if (SQL_SUCCESS == price.bindParameter(MDF_THEATER, PRICE_CODE)
							&& SQL_SUCCESS ==  dbHelper.execute(MDF_THEATER, L"DELETE FROM price WHERE code=?;"))
						{
							return;
						}
					}
				}
			}
		}

		cout << "오류가 발생했습니다.(check&deletePrice)\n";
		system("pause");
	}
}


