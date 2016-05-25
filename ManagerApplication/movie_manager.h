#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"

class MovieManager {
public:
	MovieManager(DBHelper &);
private:
	DBHelper &dbHelper;

	enum movieManagerFunction 
	{
		DELETE_MOVIE = 1,
		REGISTER_MOVIE,
	} typedef MOVIE_MANAGER_FUNCTION;

	void manageMovie(MOVIE_MANAGER_FUNCTION);
	void showRecent();
};

#endif // !MOVIE_MANAGER_H