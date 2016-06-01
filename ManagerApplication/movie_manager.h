#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"

class MovieManager {
public:
	MovieManager();
private:
	void checkAndDeleteMovie();
	void registereMovie();
	void showRecent();
};

#endif // !MOVIE_MANAGER_H