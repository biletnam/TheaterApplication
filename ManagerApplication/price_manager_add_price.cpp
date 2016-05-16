#include "price_manager.h"

FNRETURN PriceManager::addPrice()
{
	system("cls");
	cout <<
		"극장 관리 시스템\n"
		" > 가격 정보 관리\n\n"
		"  > 가격 정보 추가\n\n";

	Price price;
	SQLHSTMT &stmt = dbHelper.theaterStmt;
	cout << "가격 코드를 입력하세요: ";
	cin >> price.code;

	SQLCancel(stmt);
	SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_WVARCHAR,
			sizeof price.code, 0, &price.code, 0, NULL);
	SQLExecDirect(stmt, L"SELECT * FROM price WHERE code=?;", SQL_NTS);
	SQLFetch(stmt);


	cout << "가격 이름을 입력하세요: ";
	cin >> price.name;

	cout << "가격(원)을 입력하세요: ";
	cin >> price.won;

	return FUNCTION_ERROR;
}