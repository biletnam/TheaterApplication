#include "movie.h"

FNRETURN Movie::choose(MovieTable movieTable)
{
	switch (search(movieTable))
	{
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	case FUNCTION_SUCCESS:
		cout <<
			"0. ���\n"
			"\n"
			"����: ";
		if (FUNCTION_SUCCESS == dbHelper.moveCursor(MDF_THEATER))
		{
			return FUNCTION_SUCCESS;
		}
		else
		{
			cout << "\n������ �߻��߽��ϴ�.(Movie.choose)\n";
			system("pause");
		}
	}

	return FUNCTION_ERROR;
}