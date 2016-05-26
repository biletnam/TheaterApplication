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
		cout << "\n������ �߻��߽��ϴ�.(Movie.show)\n";
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
				cout << "\n��ϵ� ��ȭ�� �����ϴ�\n";
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
