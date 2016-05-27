#include "movie.h"

FNRETURN Movie::show(DBHelper &dbHelper)
{
	bindCol(MDF_THEATER, MOVIE_CODE);
	bindCol(MDF_THEATER, MOVIE_TITLE);
	bindCol(MDF_THEATER, MOVIE_DIRECTOR);
	bindCol(MDF_THEATER, MOVIE_AGE);
	bindCol(MDF_THEATER, MOVIE_YEAR);
	bindCol(MDF_THEATER, MOVIE_RUNNINGTIME);
	
	if (SQL_SUCCESS != dbHelper.execute(MDF_THEATER))
	{
		cout << "\n오류가 발생했습니다.(Movie.show)\n";
		system("pause");

		return FUNCTION_ERROR;
	}

	for (size_t i = 1;; i++)
	{
		switch (dbHelper.fetch(MDF_THEATER))
		{
		case SQL_SUCCESS:
			cout << i << ". ";
			show();
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "\n등록된 영화가 없습니다\n";
				system("pause");
				return FUNCTION_NULL;
			}
			else
			{
				return FUNCTION_SUCCESS;
			}		
		}
	}
}

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
