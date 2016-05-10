#include "price.h"

int16_t Price::choose(DBHelper &dbHelper)
{
	SQLHSTMT &stmt = dbHelper.theaterStmt;

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
			}
			else if (dbHelper.moveCursor(stmt, "가격을 선택하세요") == true)
			{

			}
			break;
		default:
			cout << "오류가 발생했습니다.\n";
			//_getch();
		}
	}

	return int16_t();
}


