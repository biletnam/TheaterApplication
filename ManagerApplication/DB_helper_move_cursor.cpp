#include "DB_helper.h"

FNRETURN DBHelper::moveCursor(SQLHSTMT& stmt, const char* output)
{
	SQLINTEGER rowCount = 0;
	
	if (SQLRowCount(stmt, &rowCount) == SQL_SUCCESS && rowCount > 0)
	{
		cout << output;
		FNRETURN choice = inputInteger();

		if (choice == FUNCTION_CANCEL)
		{
			return FUNCTION_CANCEL;
		}
		else if (choice == FUNCTION_ERROR || choice > rowCount)
		{
			cout << "\n잘못된 입력입니다.";
		}
		else
		{
			return
				SQLFetchScroll(stmt, SQL_FETCH_ABSOLUTE, choice) == SQL_SUCCESS
				? FUNCTION_SUCCESS : FUNCTION_ERROR;
		}
	}
	else
	{
		cout << "\n오류가 발생했습니다.";
	}

	cout << "(moveCursor)\n";
	system("pause");
	
	return FUNCTION_ERROR;
}