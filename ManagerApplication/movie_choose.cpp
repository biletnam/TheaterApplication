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
		switch (dbHelper.moveCursor(MDF_THEATER))
		{
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		case FUNCTION_ERROR:
			cout << "\n오류가 발생했습니다.(Movie.choose)\n";
			system("pause");
		case FUNCTION_CANCEL:
			return FUNCTION_CANCEL;
		}
	case FUNCTION_ERROR:
	default:
		return FUNCTION_ERROR;
	}
}