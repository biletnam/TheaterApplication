#include "movie.h"

SQLRETURN Movie::bindCol(MDF_ENUM mdf, MOVIE_INFO info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return dbHelper.bindCol(MDF_THEATER, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return dbHelper.bindCol(MDF_THEATER, BIND_STRING, director);
	case MOVIE_AGE:
		return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
		return dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &runningTime);
	}
	
	return SQLRETURN();
}

SQLRETURN Movie::bindParameter(MDF_ENUM mdf, MOVIE_INFO info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return dbHelper.bindParameter(MDF_THEATER, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return dbHelper.bindParameter(MDF_THEATER, BIND_STRING, director);
	case MOVIE_AGE:
		return dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
		return dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &runningTime);
	}

	return SQLRETURN();
}

SQLRETURN Movie::getData(MDF_ENUM mdf, SQLUSMALLINT column, MOVIE_INFO info)
{
	switch (info)
	{
	case MOVIE_CODE:
		return dbHelper.getData(MDF_THEATER, column, BIND_INTEGER, &code);
	case MOVIE_TITLE:
		return dbHelper.getData(MDF_THEATER, column, BIND_STRING, title);
	case MOVIE_DIRECTOR:
		return dbHelper.getData(MDF_THEATER, column, BIND_STRING, director);
	case MOVIE_AGE:
		return dbHelper.getData(MDF_THEATER, column, BIND_INTEGER, &age);
	case MOVIE_YEAR:
		return dbHelper.getData(MDF_THEATER, column, BIND_INTEGER, &year);
	case MOVIE_RUNNINGTIME:
		return dbHelper.getData(MDF_THEATER, column, BIND_INTEGER, &runningTime);
	}

	return SQLRETURN();
}
