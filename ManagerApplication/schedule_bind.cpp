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

SQLRETURN Schedule::bindParameter(ScheduleInfo scheduleInfo)
{
	switch (scheduleInfo)
	{
	case SCHEDULE_SCREEN:
		return screen.bindParameter(MDF_THEATER, SCREEN_NUMBER);
	case SCHEDULE_START_TIME:
		return DBHelper::bindParameter(MDF_THEATER, BIND_INTEGER, &startTime);
	case SCHEDULE_END_TIME:
		return DBHelper::bindParameter(MDF_THEATER, BIND_INTEGER, &endTime);
	case SCHEDULE_ID:
		return DBHelper::bindParameter(MDF_THEATER, BIND_INTEGER, &id);
	case SCHEDULE_MOVIE:
		if (SQL_SUCCESS == movie.bindParameter(MDF_SCHEDULE, MOVIE_CODE)
			&& SQL_SUCCESS == movie.bindParameter(MDF_SCHEDULE, MOVIE_TITLE)
			&& SQL_SUCCESS == movie.bindParameter(MDF_SCHEDULE, MOVIE_AGE))
		{
			return SQL_SUCCESS;
		}
	}

	return SQL_ERROR;
}
