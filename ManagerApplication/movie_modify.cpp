#include "movie.h"

FNRETURN Movie::modify(ModifyMovieType type)
{
	if (code > 0)
	{
		cout << "선택한 영화 정보:\n";
		show();
		cout << ((type == DELETE_MOVIE) ? "\n삭제하시겠습니까?(y/n): " : "\n등록하시겠습니까?(y/n): ");
		char yn;
		switch (inputYN(yn))
		{
		case FUNCTION_ERROR:
			cout << "\n잘못된 입력입니다.\n";
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
					cout << ((type == DELETE_MOVIE) ? "\n삭제되었습니다.\n" : "\n등록되었습니다.\n");
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(Movie::modify)\n";
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
