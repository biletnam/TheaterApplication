#include "movie.h"

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

void Movie::show(MOVIE_INFO info)
{
	switch (info)
	{
	case MOVIE_CODE:
		cout << code;
		break;
	case MOVIE_TITLE:
		cout << title;
		break;
	case MOVIE_DIRECTOR:
		cout << director;
		break;
	case MOVIE_AGE:
		cout << age;
		break;
	case MOVIE_YEAR:
		cout << year;
		break;
	case MOVIE_RUNNINGTIME:
		cout << runningTime;
	}
}
