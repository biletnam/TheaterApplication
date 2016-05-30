#include "schedule_manager.h"

void ScheduleManager::registerPrice(Schedule &schedule)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영 일정 확인/수정\n"
		"   > 가격 등록\n\n"

		"선택한 상영 일정\n";
	schedule.show();
	cout << endl;

	Price price;
	SQLHSTMT &theaterStmt = price.getStmt(MDF_THEATER);
	SQLCancel(theaterStmt);
	price.bindCol(theaterStmt);
	SQLRETURN ret = SQLExecDirect(theaterStmt, L"SELECT code, name, won FROM price;", SQL_NTS);
	if (ret != SQL_SUCCESS)
	{
		cout << "오류가 발생했습니다.(registerPrice)\n";
		system("pause");
		return;
	}

	for (int i = 1; SQL_SUCCESS == ret; i++)
	{
		switch (ret = SQLFetch(theaterStmt))
		{
		case SQL_SUCCESS:
			price.show();
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "등록된 가격 정보가 없습니다.\n";
				system("pause");
				return;
			}

			cout << "0. 종료\n";
			switch (price.moveCursor(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
			{
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L""
					"INSERT INTO d%d "
					"(movie_code, movie_title, age, start_time, end_time, screen, price_code, price_name, price_won) "
					"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);", schedule.date.getValue());
					
				schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
				schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_TITLE);
				schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_AGE);
				schedule.time.bindParameter(MDF_SALE_INFO, START_TIME);
				schedule.time.bindParameter(MDF_SALE_INFO, END_TIME);
				schedule.screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);
				price.bindParameter(MDF_SALE_INFO, PRICE_CODE);
				price.bindParameter(MDF_SALE_INFO, PRICE_NAME);
				price.bindParameter(MDF_SALE_INFO, PRICE_WON);

				if (SQL_SUCCESS == price.execute(MDF_SALE_INFO, sql))
				{
					cout << "가격이 등록되었습니다.\n";
				}
				else
				{
					cout << "오류가 발생했습니다.(registerPrice)\n";
				}
				system("pause");
			}
			}
		}
	}
}
