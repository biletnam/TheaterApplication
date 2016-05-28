#include "movie.h"

SQLRETURN Movie::bindCol(MdfEnum mdf, MovieInfo info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return dbHelper.bindCol(mdf, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return dbHelper.bindCol(mdf, BIND_STRING, director);
	case MOVIE_AGE:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
	default:
		return dbHelper.bindCol(mdf, BIND_INTEGER, &runningTime);
	}
}

SQLRETURN Movie::bindParameter(MdfEnum mdf, MovieInfo info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return dbHelper.bindParameter(mdf, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return dbHelper.bindParameter(mdf, BIND_STRING, director);
	case MOVIE_AGE:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
	default:
		return dbHelper.bindParameter(mdf, BIND_INTEGER, &runningTime);
	}
}

SQLRETURN Movie::getData(MdfEnum mdf, SQLUSMALLINT column, MovieInfo info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return dbHelper.getData(mdf, column, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return dbHelper.getData(mdf, column, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return dbHelper.getData(mdf, column, BIND_STRING, director);
	case MOVIE_AGE:
		return dbHelper.getData(mdf, column, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return dbHelper.getData(mdf, column, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
	default:
		return dbHelper.getData(mdf, column, BIND_INTEGER, &runningTime);
	}
}
