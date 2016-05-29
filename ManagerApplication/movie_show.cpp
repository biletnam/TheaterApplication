#include "movie.h"

FNRETURN Movie::showSelectResult()
{
	bindCol(MDF_THEATER, MOVIE_CODE);
	bindCol(MDF_THEATER, MOVIE_TITLE);
	bindCol(MDF_THEATER, MOVIE_DIRECTOR);
	bindCol(MDF_THEATER, MOVIE_AGE);
	bindCol(MDF_THEATER, MOVIE_YEAR);
	bindCol(MDF_THEATER, MOVIE_RUNNINGTIME);

	if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER))
	{
		cout << endl;
		for (size_t i = 1;; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "등록된 영화가 없습니다\n";
					return FUNCTION_NULL;
				}
				else
				{
					return FUNCTION_SUCCESS;
				}
			}
			break;
		}
	}

	cout << "오류가 발생했습니다.(Movie.showSelectResult)\n";
	system("pause");
	return FUNCTION_ERROR;
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