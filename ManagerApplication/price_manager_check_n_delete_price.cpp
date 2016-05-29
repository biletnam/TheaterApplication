#include "price_manager.h"

void PriceManager::checkAndDeletePrice()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ���� ���� ����\n"
			"  > ���� ���� Ȯ��/����\n\n";

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
					cout << "��ϵ� ���� ������ �����ϴ�.\n";
					system("pause");
					return;
				}
				else
				{
					cout << 
						"0. ����\n"
						"\n"
						"������ ���� ������ �����ϼ���: ";

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

		cout << "������ �߻��߽��ϴ�.(check&deletePrice)\n";
		system("pause");
	}
}


