#include "schedule.h"

FNRETURN Schedule::bindCol()
{
	SQLHSTMT &stmt = getStmt(MDF_SALE_INFO);

	if (movie.bindCol(MDF_SALE_INFO, MOVIE_CODE) == SQL_SUCCESS
		&& movie.bindCol(MDF_SALE_INFO, MOVIE_TITLE) == SQL_SUCCESS
		&& movie.bindCol(MDF_SALE_INFO, MOVIE_AGE) == SQL_SUCCESS
		&& time.bindCol(MDF_SALE_INFO, START_TIME) == SQL_SUCCESS
		&& time.bindCol(MDF_SALE_INFO, END_TIME) == SQL_SUCCESS)
	{
		return FUNCTION_SUCCESS;
	}
	else
	{
		return FUNCTION_ERROR;
	}
}
