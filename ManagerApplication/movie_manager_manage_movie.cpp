#include "movie_manager.h"

void MovieManager::manageMovie(MovieManagerFunction function)
{
	Movie movie;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n";
		cout << ((CHECK_N_DELETE_MOVIE == function) ? 
		"  > ����� ��ȭ Ȯ�� / ����\n" : "  > ���ο� ��ȭ ���\n");
		cout << endl;

		if (movie.getCode() != 0)
		{
			(CHECK_N_DELETE_MOVIE == function) ?
				movie.modify(DELETE_MOVIE) : movie.modify(INSERT_MOVIE);
		}
		else
		{
			switch (movie.search(
				((CHECK_N_DELETE_MOVIE == function) ? MOVIE_TABLE_INTERNAL : MOVIE_TABLE_EXTERNAL)))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
				switch (movie.choose())
				{
				case FUNCTION_NULL:
					cout << "��ϵ� ��ȭ�� �����ϴ�.\n";
					system("pause");
				case FUNCTION_CANCEL:
				case FUNCTION_ERROR:
					movie.initialize();
				}
			}
		}

		/*else if (FUNCTION_CANCEL 
			== movie.choose(
			((CHECK_N_DELETE_MOVIE == function) ? 
				MOVIE_TABLE_INTERNAL : MOVIE_TABLE_EXTERNAL)))
		{
			return;
		}*/
	}
}