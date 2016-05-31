#include "movie.h"

SQLRETURN Movie::del()
{
	bindParameter(MDF_THEATER, MOVIE_CODE);
	if (SQL_SUCCESS == execute(MDF_THEATER, L"DELETE FROM movie_internal WHERE movie_code=?;"))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}

SQLRETURN Movie::insert()
{
	bindParameter(MDF_THEATER, MOVIE_CODE);
	if (SQL_SUCCESS
		== execute(MDF_THEATER, L""
			"INSERT INTO "
			"movie_internal (movie_code, title, director, age, year, running_time) "
			"SELECT movie_code, title, director, age, year, running_time "
			"FROM movie_external WHERE movie_code=?;"))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}
