#include "schedule.h"

SQLRETURN Schedule::bindCol()
{
	if (SQL_SUCCESS == DBHelper::bindCol(MDF_SCHEDULE, BIND_INTEGER, &id)
		&& SQL_SUCCESS == movie.bindCol(MDF_SCHEDULE, MOVIE_CODE)
		&& SQL_SUCCESS == movie.bindCol(MDF_SCHEDULE, MOVIE_TITLE) == SQL_SUCCESS
		&& SQL_SUCCESS == movie.bindCol(MDF_SCHEDULE, MOVIE_AGE) == SQL_SUCCESS
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_SCHEDULE, BIND_INTEGER, &startTime)
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_SCHEDULE, BIND_INTEGER, &endTime))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}

SQLRETURN Schedule::bindParameter()
{
	if (SQL_SUCCESS == movie.bindParameter(MDF_SCHEDULE, MOVIE_CODE)
		&& SQL_SUCCESS == movie.bindParameter(MDF_SCHEDULE, MOVIE_TITLE)
		&& SQL_SUCCESS == movie.bindParameter(MDF_SCHEDULE, MOVIE_AGE)
		&& SQL_SUCCESS == DBHelper::bindParameter(MDF_SCHEDULE, BIND_INTEGER, &startTime)
		&& SQL_SUCCESS == DBHelper::bindParameter(MDF_SCHEDULE, BIND_INTEGER, &endTime)
		&& SQL_SUCCESS == screen.bindParameter(MDF_SCHEDULE, SCREEN_NUMBER))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}