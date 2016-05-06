#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"

class MovieManager {
public:
	MovieManager(DBHelper&);
private:
	void checkRegistration();
	void registerMovie();
	void deleteMovie();
	
	DBHelper dbHelper;
};

#endif // !MOVIE_MANAGER_H