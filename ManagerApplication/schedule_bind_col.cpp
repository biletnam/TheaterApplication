#include "schedule.h"

FNRETURN Schedule::bindCol()
{
	SQLHSTMT &stmt = dbHelper.getStmt(MDF_SALE_INFO);

	if (SQLBindCol(stmt, 1, SQL_INTEGER, &movie.code, sizeof movie.code, NULL) == SQL_SUCCESS
		&& SQLBindCol(stmt, 2, SQL_CHAR, movie.title, BUFSIZ, NULL) == SQL_SUCCESS
		&& SQLBindCol(stmt, 3, SQL_INTEGER, &movie.age, sizeof movie.age, NULL) == SQL_SUCCESS
		&& SQLBindCol(stmt, 4, SQL_INTEGER, &startTime, sizeof startTime, NULL) == SQL_SUCCESS
		&& SQLBindCol(stmt, 5, SQL_INTEGER, &endTime, sizeof endTime, NULL) == SQL_SUCCESS)
	{
		return FUNCTION_SUCCESS;
	}
	else
	{
		return FUNCTION_ERROR;
	}
}
