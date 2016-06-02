#include "schedule.h"

SQLRETURN Schedule::bindParameter(MdfEnum mdf)
{
	return DBHelper::bindParameter(mdf, BIND_INTEGER, &id);
}

SQLRETURN Schedule::bindCol()
{
	if (SQL_SUCCESS == DBHelper::bindCol(MDF_SCHEDULE, BIND_INTEGER, &id)
		&&SQL_SUCCESS == movie.bindCol(MDF_SCHEDULE, MOVIE_CODE)
		&& SQL_SUCCESS == movie.bindCol(MDF_SCHEDULE, MOVIE_TITLE) == SQL_SUCCESS
		&& SQL_SUCCESS == movie.bindCol(MDF_SCHEDULE, MOVIE_AGE) == SQL_SUCCESS
		&& SQL_SUCCESS == time.bindCol(MDF_SCHEDULE, START_TIME) == SQL_SUCCESS
		&& SQL_SUCCESS == time.bindCol(MDF_SCHEDULE, END_TIME) == SQL_SUCCESS)
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}
