#include "movie.h"

FNRETURN Movie::showRecent()
{
	cout << "�ֱ� ��ϵ� ��ȭ ���(10��)\n";

	Movie movie;
	movie.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");
	movie.bindCol();
	return movie.showSelectResult(MDF_THEATER);
}

void Movie::show()
{
	cout << title
		<< "(" << director << "), "
		<< runningTime << "��, ";
	if (age == 0)
	{
		cout << "��ü";
	}
	else
	{
		cout << age << "��";
	}
	cout << ", " << year << "��\n";
}
