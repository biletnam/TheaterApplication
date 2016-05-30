#include "movie.h"

SQLRETURN Movie::bindCol()
{
	if (SQL_SUCCESS == DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &code)
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_THEATER, BIND_STRING, title)
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_THEATER, BIND_STRING, director)
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &age)
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &year)
		&& SQL_SUCCESS == DBHelper::bindCol(MDF_THEATER, BIND_INTEGER, &runningTime))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}

SQLRETURN Movie::bindCol(MdfEnum mdf, MovieInfo info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return DBHelper::bindCol(mdf, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return DBHelper::bindCol(mdf, BIND_STRING, director);
	case MOVIE_AGE:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
	default:
		return DBHelper::bindCol(mdf, BIND_INTEGER, &runningTime);
	}
}

SQLRETURN Movie::bindParameter(MdfEnum mdf, MovieInfo info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return DBHelper::bindParameter(mdf, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return DBHelper::bindParameter(mdf, BIND_STRING, director);
	case MOVIE_AGE:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
	default:
		return DBHelper::bindParameter(mdf, BIND_INTEGER, &runningTime);
	}
}

SQLRETURN Movie::getData(MdfEnum mdf, SQLUSMALLINT column, MovieInfo info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return DBHelper::getData(mdf, column, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return DBHelper::getData(mdf, column, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return DBHelper::getData(mdf, column, BIND_STRING, director);
	case MOVIE_AGE:
		return DBHelper::getData(mdf, column, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return DBHelper::getData(mdf, column, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
	default:
		return DBHelper::getData(mdf, column, BIND_INTEGER, &runningTime);
	}
}
