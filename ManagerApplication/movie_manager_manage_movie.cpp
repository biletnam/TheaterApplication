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
				movie.modify(MODIFY_DELETE) : movie.modify(MODIFY_INSERT);
		}
		else
		{
			switch (movie.search(
				((CHECK_N_DELETE_MOVIE == function) ? MOVIE_TABLE_INTERNAL : MOVIE_TABLE_EXTERNAL)))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
				cout << endl;
				switch (movie.choose(MDF_THEATER))
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
	}
}