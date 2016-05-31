#include "schedule.h"

SQLRETURN Schedule::del()
{
	SQLWCHAR saleInfoSql[BUFSIZ];
	swprintf_s(saleInfoSql,	
		L"DELETE FROM d%d WHERE movie_code=? AND screen=? AND start_time=?;", 
		date.getValue());
	movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
	screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);
	time.bindParameter(MDF_SALE_INFO, START_TIME);

	SQLWCHAR seatSql[BUFSIZ];
	swprintf_s(seatSql, L"DROP TABLE d%ds%dt%d;", date.getValue(), screen.getNumber(), time.getStartTime());

	SQLCancel(DBHelper::getStmt(MDF_SALE_INFO));
	SQLCancel(DBHelper::getStmt(MDF_SEAT));
	if (SQLExecDirect(DBHelper::getStmt(MDF_SALE_INFO), saleInfoSql, SQL_NTS) == SQL_SUCCESS
		&& SQLExecDirect(DBHelper::getStmt(MDF_SEAT), seatSql, SQL_NTS) == SQL_SUCCESS)
	{
		cout << "삭제되었습니다.\n";
	}
	else
	{
		cout << "오류가 발생했습니다.\n";
	}
	system("pause");

	return SQLRETURN();
}
