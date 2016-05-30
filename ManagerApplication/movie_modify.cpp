#include "movie.h"

FNRETURN Movie::modify(ModifyMovieType type)
{
	if (code > 0)
	{
		cout << "������ ��ȭ ����:\n";
		show();
		cout << ((type == DELETE_MOVIE) ? "\n�����Ͻðڽ��ϱ�?(y/n): " : "\n����Ͻðڽ��ϱ�?(y/n): ");
		char yn;
		switch (inputYN(yn))
		{
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			switch (yn)
			{
			case 'y':case 'Y':
				if (SQL_SUCCESS == bindParameter(MDF_THEATER, MOVIE_CODE)
					&& SQL_SUCCESS ==
					dbHelper.execute(MDF_THEATER, ((type == DELETE_MOVIE) ? L""
						"DELETE FROM movie_internal WHERE movie_code=?;" : L""
						"INSERT INTO "
						"movie_internal (movie_code, title, director, age, year, running_time) "
						"SELECT movie_code, title, director, age, year, running_time "
						"FROM movie_external WHERE movie_code=?;" )))
				{
					cout << ((type == DELETE_MOVIE) ? "\n�����Ǿ����ϴ�.\n" : "\n��ϵǾ����ϴ�.\n");
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(Movie::modify)\n";
					system("pause");
					return FUNCTION_ERROR;
				}
			case 'n':case 'N':
				code = 0;
				return FUNCTION_SUCCESS;
			}
		}
	}

	return FUNCTION_SUCCESS;
}
