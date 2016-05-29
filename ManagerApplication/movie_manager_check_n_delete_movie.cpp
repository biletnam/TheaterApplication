#include "movie_manager.h"

void MovieManager::checkAndDeleteMovie()
{
	Movie movie(dbHelper);
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 영화 정보 관리\n"
			"  > 등록한 영화 확인 / 삭제\n"
			"\n";

		if (movie.getCode() != 0)
		{
			cout << "선택한 영화 정보:\n";
			movie.show();
			cout << "\n삭제하시겠습니까?(y/n)";
			char yn;
			switch (inputYN(yn))
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				continue;
			case FUNCTION_SUCCESS:
				switch (yn)
				{
				case 'y':case 'Y':
					if (SQL_SUCCESS == movie.bindParameter(MDF_THEATER, MOVIE_CODE)
						&& SQL_SUCCESS ==
						dbHelper.execute(MDF_THEATER, L"DELETE FROM movie_internal WHERE movie_code=?;"))
					{
						cout << "\n삭제되었습니다.\n";
					}
					else
					{
						cout << "\n오류가 발생했습니다.(checkAndDeleteMovie)\n";
					}
					system("pause");
				case 'n':case 'N':
					movie.setCode(0);
				}
				continue;
			}
		}

		switch (movie.search(MOVIE_TABLE_INTERNAL))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_NULL:
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			cout <<
				"0. 취소\n"
				"\n"
				"선택: ";

			switch (dbHelper.moveCursor(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
			case FUNCTION_ERROR:
				movie.setCode(0);
			}
		}
	}
}