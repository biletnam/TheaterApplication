#include "movie.h"

FNRETURN Movie::show(DBHelper &dbHelper)
{
	dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &code);
	dbHelper.bindCol(MDF_THEATER, BIND_STRING, title);
	dbHelper.bindCol(MDF_THEATER, BIND_STRING, director);
	dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &age);
	dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &year);
	dbHelper.bindCol(MDF_THEATER, BIND_INTEGER, &runningTime);
	
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
