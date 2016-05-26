#include "price.h"

FNRETURN Price::inputCode()
{
	cout << "���� �ڵ带 �Է��ϼ���(0�� �Է��ϸ� ����): ";

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
		cout << "�̹� �����ϴ� ���� �ڵ��Դϴ�.\n";
		break;
	case SQL_NO_DATA:
		return FUNCTION_SUCCESS;
	default:
		cout << "������ �߻��߽��ϴ�.\n";
	}

	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Price::inputName()
{
	cout << "���� �̸��� �Է��ϼ���(0�� �Է��ϸ� ����): ";
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
		cout << "�̹� �����ϴ� ���� �̸��Դϴ�.\n";
		break;
	case SQL_NO_DATA:
		return FUNCTION_SUCCESS;
	default:
		cout << "������ �߻��߽��ϴ�.\n";
	}

	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Price::inputWon()
{
	cout << "����(��)�� �Է��ϼ���(0�� �Է��ϸ� ����): ";
	cin >> won;

	if ((won = inputInteger()) == FUNCTION_CANCEL)
	{
		return FUNCTION_CANCEL;
	}

	return FUNCTION_SUCCESS;
}
