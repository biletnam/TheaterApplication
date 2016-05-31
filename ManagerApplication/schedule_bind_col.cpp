#include "schedule.h"

SQLRETURN Schedule::bindCol()
{
	if (movie.bindCol(MDF_SALE_INFO, MOVIE_CODE) == SQL_SUCCESS
		&& movie.bindCol(MDF_SALE_INFO, MOVIE_TITLE) == SQL_SUCCESS
		&& movie.bindCol(MDF_SALE_INFO, MOVIE_AGE) == SQL_SUCCESS
		&& time.bindCol(MDF_SALE_INFO, START_TIME) == SQL_SUCCESS
		&& time.bindCol(MDF_SALE_INFO, END_TIME) == SQL_SUCCESS)
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}
