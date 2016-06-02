#include "schedule_manager.h"

void ScheduleManager::checkAndDeletePrice(Schedule &schedule)
{
	for (Price price;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 확인/수정\n"
			"   > 가격 정보 확인/삭제\n"
			"\n"
			"선택한 상영 일정\n";
		schedule.show();
		cout << endl;

		if (0 < price.getCode())
		{
			cout << "\n선택한 가격 정보\n";
			price.show();

			cout << "\n삭제하시겠습니까?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"DELETE FROM d%d WHERE shedule_id=%d AND code=%d;", 
					schedule.date.getValue(), schedule.getId(), price.getCode());
				if (SQL_SUCCESS == price.execute(MDF_PRICE, sql))
				{
					cout << "\n삭제되었습니다.\n";
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(checkAndDeletePrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else
		{
			SQLWCHAR sql[BUFSIZ];
			swprintf_s(sql, L"SELECT code, name, won FROM d%d WHERE schedule_id=%d;"
				, schedule.date.getValue(), schedule.getId());
			if (SQL_SUCCESS != price.bindCol(MDF_PRICE)
				|| SQL_SUCCESS != price.prepare(MDF_PRICE, sql))
			{
				cout << "오류가 발생했습니다.(checkAndDeletePrice)\n";
				system("pause");
				return;
			}

			switch (price.choose(MDF_PRICE))
			{
			case FUNCTION_NULL:
				cout << "등록된 가격 정보가 없습니다.\n";
				system("pause");
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
			case FUNCTION_ERROR:
				break;
			}
		}
	}
}