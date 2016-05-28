#include "DB_helper.h"

FNRETURN DBHelper::moveCursor(MDF_ENUM mdf)
{
	SQLINTEGER rowCount = 0;
	
	if (SQL_SUCCESS == SQLRowCount(stmt[mdf], &rowCount) && 0 < rowCount)
	{
		FNRETURN choice = inputInteger();

		if (FUNCTION_CANCEL == choice)
		{
			return FUNCTION_CANCEL;
		}
		else if (FUNCTION_ERROR == choice || choice > rowCount)
		{
			cout << "잘못된 입력입니다.(moveCursor)\n";
			system("pause");
			return FUNCTION_ERROR;
		}
		else
		{
			if (SQL_SUCCESS == SQLFetchScroll(stmt[mdf], SQL_FETCH_ABSOLUTE, choice))
			{
				return FUNCTION_SUCCESS;
			}
		}
	}

	cout << "\n오류가 발생했습니다.(moveCursor)\n";
	system("pause");
	
	return FUNCTION_ERROR;
}