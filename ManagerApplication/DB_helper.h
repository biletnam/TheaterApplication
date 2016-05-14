#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "common_header.h"

const int16_t MDF_COUNT = 4;

class DBHelper
{
public:
	DBHelper() {};

	SQLHSTMT theaterStmt;
	SQLHSTMT saleInfoStmt;
	SQLHSTMT seatStmt;
	SQLHSTMT salesRecordStmt;
	
	FNRETURN connectDB();
	FNRETURN closeDB();
	FNRETURN moveCursor(SQLHSTMT&, const char*);
private:
	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];
};

#endif // !DB_HELPER_H