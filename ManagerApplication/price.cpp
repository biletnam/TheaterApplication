#include "price.h"

Price::Price(DBHelper &dbHelper) : dbHelper(dbHelper) 
{}

FNRETURN Price::bindCol(SQLHSTMT &stmt)
{
	if (SQLBindCol(stmt, 1, SQL_INTEGER, &code, sizeof code, NULL) == SQL_SUCCESS
		&&SQLBindCol(stmt, 2, SQL_WVARCHAR, name, BUFSIZ, NULL) == SQL_SUCCESS
		&&SQLBindCol(stmt, 3, SQL_INTEGER, &won, sizeof won, NULL) == SQL_SUCCESS)
	{
		return FUNCTION_SUCCESS;
	}

	return FUNCTION_ERROR;
}

void Price::show()
{
	cout << name << "(" << code << ") " << won << "¿ø\n";
}