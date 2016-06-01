#include "schedule.h"

SQLRETURN Schedule::del()
{
	SQLWCHAR saleInfoSql[BUFSIZ];
	swprintf_s(saleInfoSql,	
		L"DELETE FROM d%d WHERE movie_code=? AND screen=? AND start_time=?;", 
		date.getValue());
	movie.bindParameter(MDF_SCHEDULE, MOVIE_CODE);
	screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);
	time.bindParameter(MDF_SALE_INFO, START_TIME);

	SQLWCHAR seatSql[BUFSIZ];
	swprintf_s(seatSql, L"DROP TABLE d%ds%dt%d;", date.getValue(), screen.getNumber(), time.getStartTime());

	// return 값 확인해야 함
	if (SQL_SUCCESS == execute(MDF_SALE_INFO, saleInfoSql)
		&& SQL_SUCCESS == execute(MDF_SEAT, seatSql) )
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}
