#include "movie.h"

void Movie::show()
{
	cout << title
		<< "(" << director << "), "
		<< runningTime << "분, ";
	if (age == 0)
	{
		cout << "전체";
	}
	else
	{
		cout << age << "세";
	}
	cout << ", " << year << "년\n";
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
