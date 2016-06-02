#include "schedule_manager.h"

void ScheduleManager::setMovie(Movie &movie)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� ���\n"
			"   > ��ȭ ����\n"
			"\n";

		switch (movie.search(MOVIE_TABLE_INTERNAL))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
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