#include "price.h"

FNRETURN Price::inputCode()
{
	cout << "가격 코드를 입력하세요(0을 입력하면 종료): ";

	if ((code = inputInteger()) == FUNCTION_CANCEL)
	{
		return FUNCTION_CANCEL;
	}

	SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);
	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
		sizeof code, 0, &code, 0, NULL);
	SQLExecDirect(stmt, L"SELECT * FROM price WHERE code=?;", SQL_NTS);

	switch (SQLFetch(stmt))
	{
	case SQL_SUCCESS:
		cout << "이미 존재하는 가격 코드입니다.\n";
		break;
	case SQL_NO_DATA:
		return FUNCTION_SUCCESS;
	default:
		cout << "오류가 발생했습니다.\n";
	}

	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Price::inputName()
{
	cout << "가격 이름을 입력하세요(0을 입력하면 종료): ";
	cin >> name;

	if (strcmp((char*)name, "0") == 0)
	{
		return FUNCTION_CANCEL;
	}

	SQLHSTMT &stmt = dbHelper.getStmt(MDF_THEATER);
	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
		BUFSIZ, 0, name, 0, NULL);
	SQLExecDirect(stmt, L"SELECT * FROM price WHERE name=?;", SQL_NTS);

	switch (SQLFetch(stmt))
	{
	case SQL_SUCCESS:
		cout << "이미 존재하는 가격 이름입니다.\n";
		break;
	case SQL_NO_DATA:
		return FUNCTION_SUCCESS;
	default:
		cout << "오류가 발생했습니다.\n";
	}

	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Price::inputWon()
{
	cout << "가격(원)을 입력하세요(0을 입력하면 종료): ";
	cin >> won;

	if ((won = inputInteger()) == FUNCTION_CANCEL)
	{
		return FUNCTION_CANCEL;
	}

	return FUNCTION_SUCCESS;
}
