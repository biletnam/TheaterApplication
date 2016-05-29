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
					cout << "��ϵ� ��ȭ�� �����ϴ�\n";
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

	cout << "������ �߻��߽��ϴ�.(Movie.showSelectResult)\n";
	system("pause");
	return FUNCTION_ERROR;
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