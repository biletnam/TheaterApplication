#include "movie_manager.h"

void MovieManager::showRecent()
{
	cout << "�ֱ� ��ϵ� ��ȭ ���(10��)\n";

	dbHelper.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");

	Movie movie;
	movie.show(dbHelper);
}
