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
				"극장 관리 시스템\n\n"

				"1. 영화 정보 관리\n"
				"2. 상영 일정 관리\n"
				"3. 가격 정보 관리\n"
				"0. 종료\n\n"

				"선택: ";

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

	DBHelper::closeDB();
	return 0;
}