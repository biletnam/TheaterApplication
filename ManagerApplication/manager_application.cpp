#include "movie_manager.h"
#include "schedule_manager.h"
#include "price_manager.h"

int main()
{
	enum ManageApplicationFunction
	{
		MOVIE_MANAGER = 1,
		SCHEDULE_MANAGER,
		PRICE_MANAGER,
	};

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

			switch (inputInteger())
			{
			case MOVIE_MANAGER:
			{
				MovieManager movieManger(dbHelper);
				break;
			}
			case SCHEDULE_MANAGER:
			{
				ScheduleManager scheduleManager(dbHelper);
				break;
			}
			case PRICE_MANAGER:
			{
				PriceManager priceManager(dbHelper);
				break;
			}
			case FUNCTION_CANCEL:
				return 0;
			default:
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