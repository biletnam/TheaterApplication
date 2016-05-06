#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <iostream>
#include <conio.h>

const uint16_t MDF_COUNT = 4;

enum {
	FUNCTION_CANCEL = 0,
	FUNCTION_SUCCESS,
	FUNCTION_NULL,
	FUNCTION_ERROR,
};

using namespace std;

class DBHelper
{
public:
	SQLHSTMT theaterStmt;
	SQLHSTMT saleInfoStmt;
	SQLHSTMT seatStmt;
	SQLHSTMT salesRecordStmt;

	bool connectDB();
	bool closeDB();
	int16_t moveCursor(SQLHSTMT&, const char*);
private:
	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];
};

#endif // !DB_HELPER_H