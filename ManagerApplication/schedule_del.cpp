#include "schedule.h"

FNRETURN Schedule::del()
{
	SQLWCHAR saleInfoSql[BUFSIZ];
	swprintf_s(saleInfoSql ,
		L"DELETE FROM d%d WHERE movie_code=%d AND screen=%d AND start_time=%d;",
		date.value, movie.code, screen.number, startTime);

	SQLWCHAR seatSql[BUFSIZ];
	swprintf_s(seatSql, L"DROP TABLE d%ds%dt%d;", date.value, screen.number, startTime);

	if (SQLExecDirect(dbHelper.getStmt(SALE_INFO), saleInfoSql, SQL_NTS) == SQL_SUCCESS
		&& SQLCancel(dbHelper.getStmt(SALE_INFO)) == SQL_SUCCESS
		&& SQLExecDirect(dbHelper.getStmt(SEAT), seatSql, SQL_NTS) == SQL_SUCCESS
		&& SQLCancel(dbHelper.getStmt(SEAT)) == SQL_SUCCESS)
	{
		cout << "삭제되었습니다.\n";
		system("pause");

		return FUNCTION_SUCCESS;
	}
	else
	{
		cout << "오류가 발생했습니다.\n";
		system("pause");

		return FUNCTION_ERROR;
	}
}
