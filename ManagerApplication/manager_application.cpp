#include "movie_manager.h"
#include "schedule_manager.h"
#include "price_manager.h"

enum
{
	MOVIE_MANAGER = 1,
	SCHEDULE_MANAGER = 2,
	PRICE_MANAGER = 3,
};

int main()
{
	DBHelper dbHelper;
	
	if (dbHelper.connectDB() == FUNCTION_SUCCESS)
	{
		int16_t choice = 3;
		do
		{
			system("cls");
			cout << 
				"���� ���� �ý���\n\n"

				"1. ��ȭ ���� ����\n"
				"2. �� ���� ����\n"
				"3. ���� ���� ����\n"
				"0. ����\n\n"

				"����: ";
			cin >> choice;

			switch (choice)
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
				break;
			default:
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\n�߸��� �Է��Դϴ�.";
				system("pause");
			}
		} while (choice != FUNCTION_CANCEL);
	}
	else 
	{
		cout << "�����ͺ��̽� ���ٿ� �����߽��ϴ�.\n";		
	}
	
	dbHelper.closeDB();
	return 0;
}