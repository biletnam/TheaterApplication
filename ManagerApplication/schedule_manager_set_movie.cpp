#include "schedule_manager.h"

void ScheduleManager::setMovie(Movie &movie)
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영 일정 등록\n"
			"   > 영화 설정\n"
			"\n";

		switch (movie.search(MOVIE_TABLE_INTERNAL))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (movie.choose(MDF_THEATER))
			{
			case FUNCTION_NULL:
				cout << "등록된 영화가 없습니다.\n";
				system("pause");
			case FUNCTION_CANCEL:
			case FUNCTION_ERROR:
				movie.initialize();
			}
		}
	}
}