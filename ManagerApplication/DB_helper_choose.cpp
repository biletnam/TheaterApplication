#include "DB_helper.h"

FNRETURN DBHelper::choose(MdfEnum mdf)
{
	switch (showSelectResult(mdf))
	{
	case FUNCTION_NULL:
		return FUNCTION_NULL;
	case FUNCTION_SUCCESS:
		initialize();
		cout <<
			"0. 취소\n"
			"\n"
			"선택: ";

		switch (moveCursor(mdf))
		{
		case FUNCTION_CANCEL:
			return FUNCTION_CANCEL;
		case FUNCTION_SUCCESS:
		}
		return FUNCTION_SUCCESS;
	}

	initialize();
	return FUNCTION_ERROR;
}