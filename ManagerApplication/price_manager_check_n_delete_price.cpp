#include "price_manager.h"

void PriceManager::checkAndDeletePrice()
{
	Price price;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ���� ���� ����\n"
			"  > ���� ���� Ȯ��/����\n";
		
		if (0 < price.getCode())
		{
			cout << "\n������ ���� ����:\n";
			price.show();

			cout << "\n�����Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				price.bindParameter(MDF_THEATER, PRICE_CODE);
				if (SQL_SUCCESS == price.execute(MDF_THEATER, L"DELETE FROM price WHERE code=?;"))
				{
					cout << "\n�����Ǿ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(PriceManager::checkAndDeletePrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else
		{
			price.bindCol(MDF_THEATER);
			if (SQL_SUCCESS != price.prepare(MDF_THEATER, L"SELECT code, name, won FROM price;"))
			{
				cout << "\n������ �߻��߽��ϴ�(PriceManager::checkAndDeletePrice).\n";
				system("pause");
				return;
			}

			price.bindCol(MDF_THEATER);
			switch (price.choose(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "��ϵ� ���� ������ �����ϴ�\n";
				system("pause");
			}
		}
	}
}


