#include "price_manager.h"

void PriceManager::addPrice()
{
	Price price;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ���� ���� ����\n"
			"  > ���� ���� �߰�\n"
			"\n";

		if (0 < price.getCode())
		{
			cout << "���ο� ���� ����\n"
				<< "���� �ڵ�: " << price.getCode() << endl;
			if (0 != *price.getName())
			{
				wcout << L"���� �̸�: " << price.getName() << endl;
				if (-1 < price.getWon())
				{
					cout << "����: " << price.getWon() << "��\n";
				}
			}
			cout << endl;
		}

		if (0 < price.getCode()
			&& 0 != *price.getName()
			&& -1 < price.getWon())
		{
			cout << "�߰��Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				price.bindParameter(MDF_THEATER, PRICE_CODE);
				price.bindParameter(MDF_THEATER, PRICE_NAME);
				price.bindParameter(MDF_THEATER, PRICE_WON);
				if (SQL_SUCCESS	== price.execute(MDF_THEATER, 
					L"INSERT INTO price (code, name, won) values(?, ?, ?);"))
				{
					cout << "\n�߰��Ǿ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(addPrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else if (FUNCTION_CANCEL == price.input())
		{
			return;
		}
	}
}
