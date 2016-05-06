#ifndef DBHELPER_H
#define DBHELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <iostream>

#define MDF_COUNT 4

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
	bool moveCursor(SQLHSTMT&, char*);
private:
	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];
};

#endif // !DBHELPER_H