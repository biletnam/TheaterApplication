#include "movie.h"

FNRETURN Movie::choose(MovieTable movieTable)
{
	if (code == 0)
	{
		switch (search(movieTable))
		{
		case FUNCTION_CANCEL:
			return FUNCTION_CANCEL;
		case FUNCTION_ERROR:
			code = 0;
			return FUNCTION_ERROR;
		case FUNCTION_NULL:
			system("pause");
			return FUNCTION_NULL;
		case FUNCTION_SUCCESS:
			code = 0;
			cout <<
				"0. 취소\n"
				"\n"
				"선택: ";

			if (FUNCTION_ERROR == dbHelper.moveCursor(MDF_THEATER))
			{
				return FUNCTION_ERROR;
			}
		}
	}

	return FUNCTION_SUCCESS;
}