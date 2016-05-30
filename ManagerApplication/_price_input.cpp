#include "price.h"

FNRETURN Price::inputCode()
{
	cout << "���� �ڵ带 �Է��ϼ���(0�� �Է��ϸ� ����): ";

	int32_t code;
	if (FUNCTION_CANCEL == inputPositiveInteger(code))
	{
		return FUNCTION_CANCEL;
	}
	else
	{
		this->code = code;
	}
	
	bindParameter(MDF_THEATER, PRICE_CODE);
	execute(MDF_THEATER, L"SELECT * FROM price WHERE code=?;");

	switch (fetch(MDF_THEATER))
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

	SQLHSTMT &stmt = getStmt(MDF_THEATER);
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
	
	int32_t won;
	if (FUNCTION_CANCEL == inputPositiveInteger(won) )
	{
		return FUNCTION_CANCEL;
	}

	return FUNCTION_SUCCESS;
}
