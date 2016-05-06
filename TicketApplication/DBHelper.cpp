#include "DBHelper.h"

#define CHOICE_QUIT 0

bool DBHelper::moveCursor(SQLHSTMT& stmt, char* output)
{
	bool isMoved = false;
	int choice;
	SQLINTEGER rowCount;
	SQLRowCount(stmt, &rowCount);

	for (;; cin.clear(), cin.ignore(100, '\n'))
	{
		
		cout << output << "(0을 입력하면 취소): ";
		cin >> choice;

		if (choice >= CHOICE_QUIT && choice <= rowCount)
		{
			if (choice != CHOICE_QUIT &&
				SQLFetchScroll(stmt, SQL_FETCH_ABSOLUTE, choice) == SQL_SUCCESS)
			{
				isMoved = true;
			}
			break;
		}
		else
		{
			cout << "잘못된 입력입니다.\n";
		}
	}
	return isMoved;
}