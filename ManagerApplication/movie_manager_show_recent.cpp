#include "movie_manager.h"

void MovieManager::showRecent()
{
	cout << "최근 등록된 영화 목록(10개)\n";

	dbHelper.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");

	Movie movie;
	movie.show(dbHelper);
}
