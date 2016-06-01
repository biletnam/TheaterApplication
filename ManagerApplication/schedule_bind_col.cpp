#include "schedule.h"

SQLRETURN Schedule::bindCol()
{
	if (movie.bindCol(MDF_SCHEDULE, MOVIE_CODE) == SQL_SUCCESS
		&& movie.bindCol(MDF_SCHEDULE, MOVIE_TITLE) == SQL_SUCCESS
		&& movie.bindCol(MDF_SCHEDULE, MOVIE_AGE) == SQL_SUCCESS
		&& time.bindCol(MDF_SCHEDULE, START_TIME) == SQL_SUCCESS
		&& time.bindCol(MDF_SCHEDULE, END_TIME) == SQL_SUCCESS)
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}
