#include "price_manager.h"

FNRETURN PriceManager::addPrice()
{
	system("cls");
	cout <<
		"���� ���� �ý���\n"
		" > ���� ���� ����\n\n"
		"  > ���� ���� �߰�\n\n";

	Price price;
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	cout << "���� �ڵ带 �Է��ϼ���: ";
	cin >> price.code;

	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_WVARCHAR,
			sizeof price.code, 0, &price.code, 0, NULL);
	SQLExecDirect(stmt, L"SELECT * FROM price WHERE code=?;", SQL_NTS);
	SQLFetch(stmt);


	cout << "���� �̸��� �Է��ϼ���: ";
	cin >> price.name;

	cout << "����(��)�� �Է��ϼ���: ";
	cin >> price.won;

	return FUNCTION_ERROR;
}