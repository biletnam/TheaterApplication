#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "common_header.h"

typedef enum
{
	MDF_THEATER,
	MDF_SALE_INFO,
	MDF_SEAT,
	MDF_SALE_RECORD,
	MDF_COUNT
} MDF_ENUM;

typedef enum
{
	BIND_INTEGER,
	BIND_STRING,
} BIND_TYPE;

class DBHelper
{
public:
	DBHelper();
	~DBHelper();

	bool isConnected() const;

	SQLRETURN bindCol(MDF_ENUM, BIND_TYPE, void *);
	SQLRETURN bindParameter(MDF_ENUM, BIND_TYPE, void *);
	SQLRETURN execute(MDF_ENUM, SQLWCHAR * = NULL);
	SQLRETURN prepare(MDF_ENUM, SQLWCHAR *);
	void initializeBindCnt();
	
	FNRETURN moveCursor(SQLHSTMT&, const char*);
	SQLHSTMT &getStmt(MDF_ENUM);
private:
	static bool _isConnected;
	
	SQLUSMALLINT bindColCnt = 0;
	SQLUSMALLINT bindParameterCnt = 0;

	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];

	void connectDB();
	void closeDB();
};

#endif // !DB_HELPER_H