#include "DB_helper.h"

FNRETURN DBHelper::moveCursor(MdfEnum mdf)
{
	SQLINTEGER rowCount = 0;
	
	if (SQL_SUCCESS == SQLRowCount(stmt[mdf], &rowCount) && 0 < rowCount)
	{
		int32_t choice = 0;
		switch (inputPositiveInteger(choice))
		{
		case FUNCTION_CANCEL:
			return FUNCTION_CANCEL;
		case FUNCTION_SUCCESS:
			if (choice <= rowCount
				&& SQL_SUCCESS == SQLFetchScroll(stmt[mdf], SQL_FETCH_ABSOLUTE, choice))
			{
				return FUNCTION_SUCCESS;
			}
		case FUNCTION_ERROR:
			cout << "잘못된 입력입니다.(moveCursor)\n";
		}
	}
	else
	{
		cout << "\n오류가 발생했습니다.(moveCursor)\n";
	}
		
	system("pause");
	return FUNCTION_ERROR;
}