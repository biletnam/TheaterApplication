#include "price_manager.h"

FNRETURN PriceManager::checkAndDeletePrice()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n"
			"  > 가격 정보 확인/삭제\n\n";

		Price price(dbHelper);
		SQLHSTMT &stmt = dbHelper.getStmt(THEATER);
		SQLCancel(stmt);
		price.bindCol(stmt);
		SQLRETURN ret = SQLExecDirect(stmt, L"SELECT code, name, won FROM price;", SQL_NTS);

		for (int i = 1; SQL_SUCCESS == ret; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". " << price.name << " " << price.won << "원\n";
				break;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록된 가격 정보가 없습니다.\n";
					system("pause");
					return FUNCTION_NULL;
				}
				else
				{
					cout << "0. 종료\n";

					switch (dbHelper.moveCursor(stmt, "\n삭제할 가격 정보를 선택하세요: "))
					{
					case FUNCTION_CANCEL:
						return FUNCTION_CANCEL;
					case FUNCTION_SUCCESS:
						if (SQL_SUCCESS == SQLBindParameter(
							stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
							sizeof price.code, 0, &price.code, 0, NULL)
							&& SQL_SUCCESS == SQLExecDirect(
								stmt, L"DELETE FROM price WHERE code=?;", SQL_NTS))
						{
							return FUNCTION_SUCCESS;
						}
					}
				}
			}
		}

		cout << "오류가 발생했습니다.(check&deletePrice)\n";
		system("pause");

		return FUNCTION_ERROR;
	}
}


