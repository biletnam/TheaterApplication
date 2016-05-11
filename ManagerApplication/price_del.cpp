#include "price.h"
#include "schedule.h"

int16_t Price::del(Schedule &schedule)
{
	for (;;)
	{
		SQLHSTMT &stmt = dbHelper.theaterStmt;
		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT id, price_code, price_name, price_won "
			"FROM d%d "
			"WHERE movie_code=%d AND start_time=%d AND screen=%d;",
			schedule.date, schedule.movie.code, schedule.startTime, schedule.screen);

		SQLINTEGER id;
		SQLBindCol(stmt, 1, SQL_INTEGER, &id, sizeof id, NULL);
		SQLBindCol(stmt, 2, SQL_INTEGER, &code, sizeof code, NULL);
		SQLBindCol(stmt, 3, SQL_WVARCHAR, name, BUFSIZ, NULL);
		SQLBindCol(stmt, 4, SQL_INTEGER, &won, sizeof won, NULL);

		SQLRETURN ret = SQLExecDirect(stmt, sql, SQL_NTS);

		for (int i = 0; ret == SQL_SUCCESS; i++)
		{
			switch (ret = SQLFetch(stmt))
			{
			case SQL_SUCCESS:
			case SQL_NO_DATA:

			default:
				break;
			}
		}

		return FUNCTION_ERROR;
	}
}