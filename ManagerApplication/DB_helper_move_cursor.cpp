#include "DB_helper.h"

FNRETURN DBHelper::moveCursor(SQLHSTMT& stmt, const char* output)
{
	SQLINTEGER rowCount = 0;
	
	if (SQLRowCount(stmt, &rowCount) == SQL_SUCCESS && rowCount > 0)
	{
		cout << output << "(0을 입력하면 취소): ";
		int16_t choice;
		cin >> choice;

		if (choice == FUNCTION_CANCEL)
		{
			return FUNCTION_CANCEL;
		}
		else if (choice > 0 && choice <= rowCount)
		{
			return
				SQLFetchScroll(stmt, SQL_FETCH_ABSOLUTE, choice) == SQL_SUCCESS
				? FUNCTION_SUCCESS : FUNCTION_ERROR;
		}
		else if(cin.fail() == true)
		{
			cin.clear();
			cin.ignore(100, '\n');
		}

		cout << "잘못된 입력입니다.(moveCursor)\n"
			"계속하려면 아무 키나 누르십시오...\n";
		_getch();
		return moveCursor(stmt, output);
	}
	else 
	{
		return FUNCTION_ERROR;
	}
}