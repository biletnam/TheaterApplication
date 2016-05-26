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
		schedule.showInfo();
		cout << endl;

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT price_code, price_name, price_won, id "
			"FROM d%d "
			"WHERE movie_code=%d AND start_time=%d AND screen=%d;",
			schedule.date.value, schedule.movie.code, schedule.startTime, schedule.screen.number);

		SQLINTEGER id;	// sale_info id

		Price price(dbHelper);
		SQLHSTMT &stmt = dbHelper.getStmt(SALE_INFO);
		SQLCancel(stmt);
		price.bindCol(stmt);
		SQLBindCol(stmt, 4, SQL_INTEGER, &id, sizeof id, NULL);

		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);
		if (ret != SQL_SUCCESS)
		{
			cout << "오류가 발생했습니다.(deletePrice)\n";
			system("pause");
			return;
		}

		cout << "0. 취소\n";
		for (size_t i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". " << price.name << " " << price.won << "원\n";
			case SQL_NO_DATA:
				if (i == 1)		// 등록된 가격이 없을 때
				{
					cout << "\n등록된 가격이 없습니다\n";
					system("pause");
					return;
				}

				cout << "0. 취소\n";
				switch (dbHelper.moveCursor(stmt, "\n삭제할 가격을 선택하세요"))
				{
				case FUNCTION_CANCEL:	// 종료
					return;
				case FUNCTION_SUCCESS:	// 가격 선택: 반복
					swprintf_s(sql, L"DELETE FROM d%d WHERE id=%d;", schedule.date.value, id);
					SQLCancel(stmt);
					if (SQL_SUCCESS == SQLExecDirect(stmt, sql, SQL_NTS))
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