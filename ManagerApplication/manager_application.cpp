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
				"극장 관리 시스템\n\n"

				"1. 영화 정보 관리\n"
				"2. 상영 일정 관리\n"
				"3. 가격 정보 관리\n"
				"0. 종료\n\n"

				"선택: ";
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
				cout << "\n잘못된 입력입니다.";
				system("pause");
			}
		} while (choice != FUNCTION_CANCEL);
	}
	else 
	{
		cout << "데이터베이스 접근에 실패했습니다.\n";		
	}
	
	dbHelper.closeDB();
	return 0;
}