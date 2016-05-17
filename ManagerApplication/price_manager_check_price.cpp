#include "price_manager.h"

FNRETURN PriceManager::checkPrice()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ���� ���� ����\n"
			"  > ���� ���� Ȯ��/����\n\n";

		Price price;
		SQLHSTMT &stmt = dbHelper.theaterStmt;
		SQLCancel(stmt);
		SQLBindCol(stmt, 1, SQL_INTEGER, &price.code, sizeof price.code, NULL);
		SQLBindCol(stmt, 2, SQL_WVARCHAR, price.name, BUFSIZ, NULL);
		SQLBindCol(stmt, 3, SQL_INTEGER, &price.won, sizeof price.won, NULL);
		SQLRETURN ret = SQLExecDirect(stmt, L"SELECT code, name, won FROM price;", SQL_NTS);

		for (int i = 1; SQL_SUCCESS == ret; i++)
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
					return FUNCTION_NULL;
				}
				else
				{
					cout << "0. ����\n";

					switch (dbHelper.moveCursor(stmt, "\n������ ���� ������ �����ϼ���: "))
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

		cout << "������ �߻��߽��ϴ�.\n";
		system("pause");

		return FUNCTION_ERROR;
	}
}


