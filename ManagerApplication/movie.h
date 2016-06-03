#ifndef MOVIE_H
#define MOVIE_H

#include "DB_helper.h"

using namespace std;

enum MovieInfo
{
	MOVIE_CODE,
	MOVIE_TITLE,
	MOVIE_DIRECTOR,
	MOVIE_AGE,
	MOVIE_YEAR,
	MOVIE_RUNNINGTIME
};

enum MovieTable
{
	MOVIE_TABLE_INTERNAL,
	MOVIE_TABLE_EXTERNAL,
};

class Movie : public DBHelper
{
public:
	FNRETURN search(MovieTable);
	
	static FNRETURN showRecent();
	void show();
	void initialize() { code = 0; };

	void setKeyword(SQLWCHAR*) const;

	SQLINTEGER getCode() { return code; };
	SQLWCHAR *getTitle() { return title; };
	SQLINTEGER getAge() { return age; };

	SQLRETURN bindCol();
	SQLRETURN bindCol(MdfEnum, MovieInfo);
	SQLRETURN bindParameter(MdfEnum, MovieInfo);
private:
	SQLINTEGER code = 0;
	SQLWCHAR title[BUFSIZ] = { 0 };
	SQLWCHAR director[BUFSIZ] = { 0 };
	SQLINTEGER age = -1;
	SQLINTEGER year = 0;
	SQLINTEGER runningTime = 0;

	SQLWCHAR keyword[BUFSIZ];
};

#endif // !MOVIE_H