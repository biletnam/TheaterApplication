#include "price.h"

FNRETURN Price::inputCode()
{
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	cout << "���� �ڵ带 �Է��ϼ���: ";
	cin >> code;

	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_WVARCHAR,
		sizeof code, 0, &code, 0, NULL);
	SQLExecDirect(stmt, L"SELECT * FROM price WHERE code=?;", SQL_NTS);
	
	if (SQLFetch(stmt) == SQL_SUCCESS)
	{
		cout << "�̹� ����\n";
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
