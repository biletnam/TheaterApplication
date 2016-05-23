#include "price_manager.h"

FNRETURN PriceManager::addPrice()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 가격 정보 관리\n\n"
			"  > 가격 정보 추가\n\n";

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