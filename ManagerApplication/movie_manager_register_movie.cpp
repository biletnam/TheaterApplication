#include "movie_manager.h"

void MovieManager::registerMovie()
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			"  > ���ο� ��ȭ ���\n\n";

		Movie movie(dbHelper);
		switch (movie.search(MOVIE_TABLE_EXTERNAL))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			cout <<
				"0. ���\n"
				"\n"
				"����: ";
			switch (dbHelper.moveCursor(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
				continue;
			case FUNCTION_SUCCESS:
				if (SQL_SUCCESS == movie.bindParameter(MDF_THEATER, MOVIE_CODE)
					&& SQL_SUCCESS == dbHelper.execute(MDF_THEATER, L""
						"INSERT INTO "
						"movie_internal (movie_code, title, director, age, year, running_time) "
						"SELECT movie_code, title, director, age, year, running_time "
						"FROM movie_external WHERE movie_code=?;"))
				{
					cout << "\n��ϵǾ����ϴ�.\n";
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(registerMovie)\n";
				}
			}
		}
		system("pause");
	}
}