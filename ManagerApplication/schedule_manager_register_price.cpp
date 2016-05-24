#include "schedule_manager.h"

FNRETURN ScheduleManager::registerPrice(Schedule &schedule)
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 상영 일정 관리\n"
		"  > 상영 일정 확인/수정\n"
		"   > 가격 등록\n\n"

		"선택한 상영 일정\n";
	schedule.showInfo();
	cout << endl;

	Price price(dbHelper);
	SQLHSTMT &theaterStmt = dbHelper.getStmt(THEATER);
	SQLCancel(theaterStmt);
	SQLBindCol(theaterStmt, 1, SQL_INTEGER, &price.code, sizeof price.code, NULL);
	SQLBindCol(theaterStmt, 2, SQL_WVARCHAR, price.name, BUFSIZ, NULL);
	SQLBindCol(theaterStmt, 3, SQL_INTEGER, &price.won, sizeof price.won, NULL);
	SQLRETURN ret = SQLExecDirect(theaterStmt, L"SELECT code, name, won FROM price;", SQL_NTS);

	for (int i = 1; SQL_SUCCESS == ret; i++)
	{
		switch (ret = SQLFetch(theaterStmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << price.name << " " << price.won << "원\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "등록된 가격 정보가 없습니다.\n";
				system("pause");
				return FUNCTION_NULL;
			}
			else
			{
				cout << "0. 종료\n";

				switch (dbHelper.moveCursor(theaterStmt, "\n선택: "))
				{
				case FUNCTION_CANCEL:
					return FUNCTION_CANCEL;
				case FUNCTION_SUCCESS:
					{
						SQLWCHAR sql[BUFSIZ];
						swprintf_s(sql, L""
							"INSERT INTO d%d "
							"(movie_code, movie_title, age, start_time, end_time, screen, price_code, price_name, price_won) "
							"VALUES (%d, ?, %d, %d, %d, %d, %d, ?, %d);",
							schedule.date.value,
							schedule.movie.code, schedule.movie.age,
							schedule.startTime, schedule.endTime,
							schedule.screen.number,
							price.code, price.won);

						SQLHSTMT saleInfoStmt = dbHelper.getStmt(SALE_INFO);
						SQLCancel(saleInfoStmt);
						SQLBindParameter(saleInfoStmt, 1, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
							BUFSIZ, 0, schedule.movie.title, 0, NULL);
						SQLBindParameter(saleInfoStmt, 2, SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_WVARCHAR,
							BUFSIZ, 0, price.name, 0, NULL);
						SQLExecDirect(saleInfoStmt, sql, SQL_NTS);
					}
				}
			}
		}
	}

	cout << "오류가 발생했습니다..\n";
	system("pause");

	return FUNCTION_ERROR;
}
