#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include "movie.h"

class MovieManager {
public:
	MovieManager();
private:
	typedef enum
	{
		CHECK_N_DELETE_MOVIE = 1,
		REGISTER_MOVIE,
	} MovieManagerFunction;

	void manageMovie(MovieManagerFunction);
	void showRecent();
};

#endif // !MOVIE_MANAGER_H