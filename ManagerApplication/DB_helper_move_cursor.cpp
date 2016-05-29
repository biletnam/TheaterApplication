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
			cout << "�߸��� �Է��Դϴ�.(moveCursor)\n";
		}
	}
	else
	{
		cout << "\n������ �߻��߽��ϴ�.(moveCursor)\n";
	}
		
	system("pause");
	return FUNCTION_ERROR;
}