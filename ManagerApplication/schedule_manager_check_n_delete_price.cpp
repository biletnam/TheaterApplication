#include "schedule_manager.h"

void ScheduleManager::checkAndDeletePrice(Schedule &schedule)
{
	for (;;)
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

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT price_code, price_name, price_won, id "
			"FROM d%d "
			"WHERE movie_code=? AND start_time=? AND screen=?;",
			schedule.date.getValue());
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
		schedule.time.bindParameter(MDF_SALE_INFO, START_TIME);
		schedule.screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);

		SQLINTEGER id;	// sale_info id
		Price price;
		price.bindCol(MDF_SALE_INFO);
		schedule.DBHelper::bindCol(MDF_SALE_INFO, BIND_INTEGER, &id);
		//SQLBindCol(stmt, 4, SQL_INTEGER, &id, sizeof id, NULL);

		if (SQL_SUCCESS != schedule.prepare(sql) )
		{
			cout << "오류가 발생했습니다.(checkAndDeletePrice)\n";
			system("pause");
			return;
		}

		switch (schedule.choose())
		{
		case FUNCTION_SUCCESS:
			swprintf_s(sql, L"DELETE FROM d%d WHERE id=%d;", schedule.date.getValue(), id);
		case FUNCTION_CANCEL:
		case FUNCTION_ERROR:
		case FUNCTION_NULL:
		default:
			break;
		}


		cout << "0. 취소\n";
		for (size_t i = 1;; i++)
		{
			switch (schedule.fetch(MDF_SALE_INFO))
			{
			case SQL_SUCCESS:
				price.show();
			case SQL_NO_DATA:
				if (i == 1)		// 등록된 가격이 없을 때
				{
					cout << "\n등록된 가격이 없습니다\n";
					system("pause");
					return;
				}

				cout << 
					"0. 취소\n"
					"\n"
					"삭제할 가격을 선택하세요";
				switch (price.moveCursor(MDF_SALE_INFO))
				{
				case FUNCTION_CANCEL:	// 종료
					return;
				case FUNCTION_SUCCESS:	// 가격 선택: 반복
					swprintf_s(sql, L"DELETE FROM d%d WHERE id=%d;", schedule.date.getValue(), id);
					if (SQL_SUCCESS == schedule.execute(MDF_SALE_INFO, sql))
					{
						cout << "가격이 삭제되었습니다.\n";
					}
					else	// 선택 에러: 반복
					{
						cout << "오류가 발생했습니다.(deletePrice)\n";
					}
					system("pause");
				}
			}
		}
	}
}