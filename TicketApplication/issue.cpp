#include "Issue.h"

Issue::Issue(DBHelper& dbHelper)
{
	this->dbHelper = dbHelper;

	if (chooseDate() == false
		|| chooseMovie() == false
		|| chooseTime() == false)
	{
		cancelIssue();
		return;
	}
	
	for (char choice;;)
	{
		
		if (choosePrice() == false)
		{
			cancelIssue();
			return;
		}
		
		do
		{
			cout << "��� �߱��Ͻðڽ��ϱ�? (y/n): ";
			cin >> choice;

			switch (choice)
			{
			case 'y':case 'Y':
				choice = 'y';
				break;
			case 'n':case 'N':
				showTicket();
				return;
			default:
				cout << "�߸��� �Է��Դϴ�.\n";
			}
		} while (choice == 'y');
	}
}

void Issue::setMaxRowCol()
{
	SQLHSTMT& stmt = dbHelper.theaterStmt;

	SQLBindCol(stmt, 1, SQL_INTEGER, &maxRow, sizeof(maxRow), NULL);
	SQLBindCol(stmt, 2, SQL_INTEGER, &maxCol, sizeof(maxCol), NULL);
	SQLExecDirect(stmt, TEXT("SELECT row, col FROM screen;"), SQL_NTS);
	SQLFetch(stmt);
	SQLCancel(stmt);
}