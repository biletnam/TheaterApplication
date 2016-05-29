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
			cout << "���� ������ �߰��Ǿ����ϴ�.\n";
		}
		else
		{
			cout << "������ �߻��߽��ϴ�.(addPrice)\n";
		}
		system("pause");
	}
}
