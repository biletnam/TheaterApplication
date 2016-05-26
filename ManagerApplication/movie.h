#ifndef MOVIE_H
#define MOVIE_H

#include "DB_helper.h"

using namespace std;

class Movie
{
public:
	SQLINTEGER code = 0;
	SQLCHAR title[BUFSIZ] = {0};
	SQLCHAR director[BUFSIZ] = {0};
	SQLSMALLINT age = -1;
	SQLSMALLINT year = -1;
	SQLSMALLINT runningTime = -1;

	FNRETURN show(DBHelper &);
	void setKeyword(SQLWCHAR*, const char*) const;
};

#endif // !MOVIE_H