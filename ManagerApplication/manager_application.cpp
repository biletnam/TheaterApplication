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
				"극장 관리 시스템\n\n"

				"1. 영화 정보 관리\n"
				"2. 상영 일정 관리\n"
				"3. 가격 정보 관리\n"
				"0. 종료\n\n"

				"선택: ";

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
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
			}
		}
	}
	else 
	{
		cout << "데이터베이스 접근에 실패했습니다.\n";		
		system("pause");
	}

	return 0;
}