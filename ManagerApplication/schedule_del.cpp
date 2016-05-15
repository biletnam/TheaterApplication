#include "schedule.h"

FNRETURN Schedule::del()
{
	SQLWCHAR saleInfoSql[BUFSIZ];
	swprintf_s(saleInfoSql ,
		L"DELETE FROM d%d WHERE movie_code=%d AND screen=%d AND start_time=%d;",
		date.value, movie.code, screen.number, startTime);

	SQLWCHAR seatSql[BUFSIZ];
	swprintf_s(seatSql, L"DROP TABLE d%ds%dt%d;", date.value, screen.number, startTime);

	if (SQLExecDirect(dbHelper.saleInfoStmt, saleInfoSql, SQL_NTS) == SQL_SUCCESS
		&& SQLCancel(dbHelper.saleInfoStmt) == SQL_SUCCESS
		&& SQLExecDirect(dbHelper.seatStmt, seatSql, SQL_NTS) == SQL_SUCCESS
		&& SQLCancel(dbHelper.seatStmt) == SQL_SUCCESS)
	{
		cout << "�����Ǿ����ϴ�.\n"
			"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
		_getch();

		return FUNCTION_SUCCESS;
	}
	else
	{
		cout << "������ �߻��߽��ϴ�.\n"
			"����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
		_getch();

		return FUNCTION_ERROR;
	}
}
