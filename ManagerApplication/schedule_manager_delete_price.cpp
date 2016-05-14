#include "schedule_manager.h"

FNRETURN ScheduleManager::deletePrice(Schedule &schedule)
{
	for (;;)
	{
		SQLHSTMT &stmt = dbHelper.theaterStmt;
		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT id, price_code, price_name, price_won "
			"FROM d%d "
			"WHERE movie_code=%d AND start_time=%d AND screen=%d;",
			schedule.date.value, schedule.movie.code, schedule.startTime, schedule.screen.number);

		SQLINTEGER id;	// sale_info id

		Price price;
		SQLBindCol(stmt, 1, SQL_INTEGER, &id, sizeof id, NULL);
		SQLBindCol(stmt, 2, SQL_INTEGER, &price.code, sizeof price.code, NULL);
		SQLBindCol(stmt, 3, SQL_WVARCHAR, price.name, BUFSIZ, NULL);
		SQLBindCol(stmt, 4, SQL_INTEGER, &price.won, sizeof price.won, NULL);

		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 1; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
				cout << i << ". " << price.name << " " << price.won << "원\n";
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "\n등록된 가격이 없습니다\n"
						"계속하려면 아무 키나 누르십시오...\n";
					_getch();

					return 0;
				}
				else
				{
					switch (dbHelper.moveCursor(stmt, "\n삭제할 가격을 선택하세요"))
					{
					case FUNCTION_SUCCESS:
					{
						swprintf_s(sql,
							L"DELETE FROM d%d WHERE id=%d;",
							schedule.date.value, id);
					}
					case FUNCTION_CANCEL:
						break;
					}
				}
			default:
				break;
			}
		}

		return FUNCTION_ERROR;
	}
}