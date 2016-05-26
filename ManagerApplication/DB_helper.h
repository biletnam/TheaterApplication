#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "common_header.h"

typedef enum
{
	THEATER,
	SALE_INFO,
	SEAT,
	SALE_RECORD,
	MDF_COUNT
} MDF_ENUM;

typedef enum
{
	INTEGER,
	CHARACTER,
} BIND_TYPE;

class DBHelper
{
public:
	DBHelper();
	~DBHelper();

	bool isConnected() const;

	void bindCol(SQLHSTMT &, SQLUSMALLINT, BIND_TYPE, void *);
	void bindParameter(SQLHSTMT &, SQLUSMALLINT, BIND_TYPE, void *);

	FNRETURN moveCursor(SQLHSTMT&, const char*);
	SQLHSTMT &getStmt(MDF_ENUM);
private:
	static bool _isConnected;

	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];

	void connectDB();
	void closeDB();
};

#endif // !DB_HELPER_H