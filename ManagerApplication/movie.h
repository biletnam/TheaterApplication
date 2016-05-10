#ifndef MOVIE_H
#define MOVIE_H

#include "DB_helper.h"

using namespace std;

class Movie
{
public:
	SQLINTEGER code = 0;
	SQLCHAR title[BUFSIZ];
	SQLCHAR director[BUFSIZ];
	SQLSMALLINT age;
	SQLSMALLINT year;
	SQLSMALLINT runningTime;

	int16_t showInfo(SQLHSTMT& stmt);
	void setKeyword(SQLWCHAR*, const char*) const;
};

#endif // !MOVIE_H