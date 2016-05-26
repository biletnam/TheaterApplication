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
				cout << i << ". " << price.name << " " << price.won << "��\n";
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
					cout << "0. ����\n";

					switch (dbHelper.moveCursor(stmt, "\n������ ���� ������ �����ϼ���: "))
					{
					case FUNCTION_CANCEL:
						return;
					case FUNCTION_SUCCESS:
						if (SQL_SUCCESS == SQLBindParameter(
							stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
							sizeof price.code, 0, &price.code, 0, NULL)
							&& SQL_SUCCESS == SQLExecDirect(
								stmt, L"DELETE FROM price WHERE code=?;", SQL_NTS))
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


