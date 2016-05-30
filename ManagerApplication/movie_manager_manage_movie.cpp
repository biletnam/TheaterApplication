#include "movie_manager.h"

void MovieManager::manageMovie(MovieManagerFunction function)
{
	Movie movie(dbHelper);
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
		else if (FUNCTION_CANCEL 
			== movie.choose(
			((CHECK_N_DELETE_MOVIE == function) ? 
				MOVIE_TABLE_INTERNAL : MOVIE_TABLE_EXTERNAL)))
		{
			return;
		}
	}
}