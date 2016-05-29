#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"

class MovieManager {
public:
	MovieManager(DBHelper &);
private:
	DBHelper &dbHelper;

	

	void checkAndDeleteMovie();
	void registerMovie();
	void showRecent();
};

#endif // !MOVIE_MANAGER_H