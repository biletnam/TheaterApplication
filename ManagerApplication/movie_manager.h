#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"

class MovieManager {
public:
	MovieManager(DBHelper *);
private:
	void registerMovie();
	void deleteMovie();
	void showRecent();
	
	DBHelper *pDBHelper;
};

#endif // !MOVIE_MANAGER_H