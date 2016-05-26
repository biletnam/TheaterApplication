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
				"���� ���� �ý���\n"
				" > ���� ���� ����\n"
				"  > ���� ���� �߰�\n"
				"\n"
				"���ο� ���� ����\n";
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
			cout << "���� ������ �߰��Ǿ����ϴ�.\n";
		}
		else
		{
			cout << "������ �߻��߽��ϴ�.(addPrice)\n";
		}
		system("pause");
	}
}