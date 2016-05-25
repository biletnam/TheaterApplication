#include "schedule.h"

void Schedule::del()
{
	SQLWCHAR saleInfoSql[BUFSIZ];
	swprintf_s(saleInfoSql ,
		L"DELETE FROM d%d WHERE movie_code=%d AND screen=%d AND start_time=%d;",
		date.value, movie.code, screen.number, startTime);

	SQLWCHAR seatSql[BUFSIZ];
	swprintf_s(seatSql, L"DROP TABLE d%ds%dt%d;", date.value, screen.number, startTime);

	SQLCancel(dbHelper.getStmt(SALE_INFO));
	SQLCancel(dbHelper.getStmt(SEAT));
	if (SQLExecDirect(dbHelper.getStmt(SALE_INFO), saleInfoSql, SQL_NTS) == SQL_SUCCESS
		&& SQLExecDirect(dbHelper.getStmt(SEAT), seatSql, SQL_NTS) == SQL_SUCCESS)
	{
		cout << "�����Ǿ����ϴ�.\n";
	}
	else
	{
		cout << "������ �߻��߽��ϴ�.\n";
	}
	system("pause");
}
