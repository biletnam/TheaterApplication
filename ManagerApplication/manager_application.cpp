#include "movie_manager.h"
#include "schedule_manager.h"
#include "price_manager.h"

int main()
{
	typedef enum
	{
		MOVIE_MANAGER = 1,
		SCHEDULE_MANAGER,
		PRICE_MANAGER,
	} ManageApplicationFunction;

	DBHelper dbHelper;
	if (dbHelper.isConnected() == true)
	{
		for(;;)
		{
			system("cls");
			cout << 
				"���� ���� �ý���\n\n"

				"1. ��ȭ ���� ����\n"
				"2. �� ���� ����\n"
				"3. ���� ���� ����\n"
				"0. ����\n\n"

				"����: ";

			int8_t function = 0;
			switch (inputPositiveInteger(function))
			{
			case FUNCTION_CANCEL:
				return 0;
			case FUNCTION_SUCCESS:
				switch (function)
				{
				case MOVIE_MANAGER:
				{
					MovieManager movieManger(dbHelper);
					continue;
				}
				case SCHEDULE_MANAGER:
				{
					ScheduleManager scheduleManager(dbHelper);
					continue;
				}
				case PRICE_MANAGER:
				{
					PriceManager priceManager(dbHelper);
					continue;
				}
				}
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
			}
		}
	}
	else 
	{
		cout << "�����ͺ��̽� ���ٿ� �����߽��ϴ�.\n";		
		system("pause");
	}

	return 0;
}