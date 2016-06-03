#include "movie_manager.h"
#include "schedule_manager.h"
#include "price_manager.h"

int main()
{
	wcin.imbue(locale("korean"));
	wcout.imbue(locale("korean"));

	typedef enum
	{
		MOVIE_MANAGER = 1,
		SCHEDULE_MANAGER,
		PRICE_MANAGER,
	} ManageApplicationFunction;

	if (FUNCTION_SUCCESS == DBHelper::connectDB())
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

			int32_t function = 0;
			switch (inputPositiveInteger(function))
			{
			case FUNCTION_CANCEL:
				return 0;
			case FUNCTION_SUCCESS:
				switch (function)
				{
				case MOVIE_MANAGER:
				{
					MovieManager movieManger;
					continue;
				}
				case SCHEDULE_MANAGER:
				{
					ScheduleManager scheduleManager;
					continue;
				}
				case PRICE_MANAGER:
				{
					PriceManager priceManager;
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

	DBHelper::closeDB();
	return 0;
}