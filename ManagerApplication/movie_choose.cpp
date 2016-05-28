#include "movie.h"

FNRETURN Movie::choose(MovieTable movieTable)
{
	switch (search(movieTable))
	{
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	case FUNCTION_SUCCESS:
		cout <<
			"0. 취소\n"
			"\n"
			"선택: ";
		if (FUNCTION_SUCCESS == dbHelper.moveCursor(MDF_THEATER))
		{
			return FUNCTION_SUCCESS;
		}
		else
		{
			cout << "\n오류가 발생했습니다.(Movie.choose)\n";
			system("pause");
		}
	}

	return FUNCTION_ERROR;
}