#include "price_manager.h"

FNRETURN PriceManager::addPrice()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ���� ���� ����\n\n"
			"  > ���� ���� �߰�\n\n";

		Price price(dbHelper);

		if (price.code == 0)
		{
			price.inputCode();
		}
		else if (price.name == NULL)
		{
			price.inputName();
		}
		else if (price.won == 0)
		{
			price.inputWon();
		}
	}
}