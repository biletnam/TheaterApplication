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
} MOVIE_INFO;

enum MovieTable
{
	MOVIE_TABLE_INTERNAL,
	MOVIE_TABLE_EXTERNAL,
};

class Movie
{
public:
	Movie(DBHelper &dbHelper) : dbHelper(dbHelper) {}

	SQLINTEGER code = 0;
	SQLCHAR title[BUFSIZ] = {0};
	SQLCHAR director[BUFSIZ] = {0};
	SQLSMALLINT age = -1;
	SQLSMALLINT year = -1;
	SQLSMALLINT runningTime = -1;

	FNRETURN search(MovieTable);
	FNRETURN choose(MovieTable);
	FNRETURN del();
	FNRETURN insert();
	void show();
	void show(MOVIE_INFO);
	void setKeyword(SQLWCHAR*) const;

	SQLRETURN bindCol(MDF_ENUM, MOVIE_INFO);
	SQLRETURN bindParameter(MDF_ENUM, MOVIE_INFO);
	SQLRETURN getData(MDF_ENUM, SQLUSMALLINT, MOVIE_INFO);
private:
	DBHelper &dbHelper;
};

#endif // !MOVIE_H