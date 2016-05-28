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
			cout << "�߸��� �Է��Դϴ�.(moveCursor)\n";
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

	cout << "\n������ �߻��߽��ϴ�.(moveCursor)\n";
	system("pause");
	
	return FUNCTION_ERROR;
}