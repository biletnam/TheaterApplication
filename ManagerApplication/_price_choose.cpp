#include "price.h"

FNRETURN Price::choose()
{
	SQLHSTMT &stmt = getStmt(MDF_THEATER);

	SQLBindCol(stmt, 1, SQL_INTEGER, &code, sizeof code, NULL);
	SQLBindCol(stmt, 2, SQL_CHAR, name, BUFSIZ, NULL);
	SQLBindCol(stmt, 3, SQL_INTEGER, &won, sizeof won, NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT code, name, won FROM price;", SQL_NTS);

	cout << "\n����\n";
	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << name << " " << won << "��\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "��� ������ ������ �����ϴ�\n";
				system("pause");
			}
			else
			{
				cout << "������ �����ϼ���";
				if (moveCursor(MDF_THEATER))
				{

				}
			}
			
			break;
		default:
			cout << "������ �߻��߽��ϴ�.\n";
			system("pause");
		}
	}

	return FNRETURN();
}



