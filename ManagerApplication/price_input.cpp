#include "price.h"

FNRETURN Price::inputCode()
{
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	cout << "가격 코드를 입력하세요: ";
	cin >> code;

	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_WVARCHAR,
		sizeof code, 0, &code, 0, NULL);
	SQLExecDirect(stmt, L"SELECT * FROM price WHERE code=?;", SQL_NTS);
	
	if (SQLFetch(stmt) == SQL_SUCCESS)
	{
		cout << "이미 존재\n";
		_getch();

		return FUNCTION_ERROR;
	}
	SQLCancel(stmt);

	return FNRETURN();
}

FNRETURN Price::inputName()
{
	return FNRETURN();
}

FNRETURN Price::inputWon()
{
	return FNRETURN();
}
