#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	DBHelper db;
	db.connectDB();

	SQLRETURN ret;
	ret = SQLExecDirect(db.theaterStmt, L"SELECT * FROM price WHERE code=1;", SQL_NTS);
	ret = SQLFetch(db.theaterStmt);
	ret = SQLFetch(db.theaterStmt);
	ret = SQLFetch(db.theaterStmt);

	L"SELECT * FROM price;";

	db.closeDB();
	return 0;
}

