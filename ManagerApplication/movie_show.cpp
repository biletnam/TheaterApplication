#include "movie.h"

FNRETURN Movie::showRecent()
{
	cout << "�ֱ� ��ϵ� ��ȭ ���(10��)";

	Movie movie;
	movie.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");
	movie.bindCol();
	return movie.showSelectResult(MDF_THEATER);
}

void Movie::show()
{
	wcout << title << "(" << director << ") " << runningTime << L"��, ";
	if (0 == age)
	{
		cout << "��ü";
	}
	else
	{
		cout << age << "��";
	}
	cout << ", " << year << "��\n";
}
