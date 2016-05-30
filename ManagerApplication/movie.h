#ifndef MOVIE_H
#define MOVIE_H

#include "DB_helper.h"

using namespace std;

typedef enum
{
	MOVIE_CODE,
	MOVIE_TITLE,
	MOVIE_DIRECTOR,
	MOVIE_AGE,
	MOVIE_YEAR,
	MOVIE_RUNNINGTIME
} MovieInfo;

typedef enum
{
	MOVIE_TABLE_INTERNAL,
	MOVIE_TABLE_EXTERNAL,
} MovieTable;

typedef enum
{
	DELETE_MOVIE,
	INSERT_MOVIE,
} ModifyMovieType;

class Movie : public DBHelper
{
public:
	FNRETURN search(MovieTable);
	//FNRETURN choose(MovieTable);
	FNRETURN modify(ModifyMovieType);
	
	//FNRETURN showSelectResult();
	void show();
	void showNullMessage();
	void initialize();

	void setKeyword(SQLWCHAR*) const;

	SQLINTEGER getCode();

	SQLRETURN bindCol();
	SQLRETURN bindCol(MdfEnum, MovieInfo);
	SQLRETURN bindParameter(MdfEnum, MovieInfo);
	SQLRETURN getData(MdfEnum, SQLUSMALLINT, MovieInfo);
private:
	SQLINTEGER code = 0;
	SQLCHAR title[BUFSIZ];
	SQLCHAR director[BUFSIZ];
	SQLSMALLINT age;
	SQLSMALLINT year;
	SQLSMALLINT runningTime;
};

#endif // !MOVIE_H