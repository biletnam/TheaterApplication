#include "movie.h"

FNRETURN Movie::showRecent()
{
	cout << "최근 등록된 영화 목록(10개)";

	Movie movie;
	movie.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");
	movie.bindCol();
	return movie.showSelectResult(MDF_THEATER);
}

void Movie::show()
{
	wcout << title << "(" << director << ") " << runningTime << L"분, ";
	if (0 == age)
	{
		cout << "전체";
	}
	else
	{
		cout << age << "세";
	}
	cout << ", " << year << "년\n";
}
