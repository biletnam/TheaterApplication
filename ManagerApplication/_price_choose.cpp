#include "price.h"

FNRETURN Price::choose()
{
	SQLHSTMT &stmt = getStmt(MDF_THEATER);

	SQLBindCol(stmt, 1, SQL_INTEGER, &code, sizeof code, NULL);
	SQLBindCol(stmt, 2, SQL_CHAR, name, BUFSIZ, NULL);
	SQLBindCol(stmt, 3, SQL_INTEGER, &won, sizeof won, NULL);
	SQLRETURN ret = SQLExecDirect(stmt, L"SELECT code, name, won FROM price;", SQL_NTS);

	cout << "\n가격\n";
	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". " << name << " " << won << "원\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "등록 가능한 가격이 없습니다\n";
				system("pause");
			}
			else
			{
				cout << "가격을 선택하세요";
				if (moveCursor(MDF_THEATER))
				{

				}
			}
			
			break;
		default:
			cout << "오류가 발생했습니다.\n";
			system("pause");
		}
	}

	return FNRETURN();
}



