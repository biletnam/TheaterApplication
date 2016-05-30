#include "movie_manager.h"

void MovieManager::showRecent()
{
	cout << "최근 등록된 영화 목록(10개)\n";
	
	Movie movie;
	movie.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");
	movie.bindCol();
	if (FUNCTION_NULL == movie.showSelectResult())
	{
		cout << "등록된 영화가 없습니다\n";
		system("pause");
	}
}
