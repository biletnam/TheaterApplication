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
} MdfEnum;

typedef enum
{
	BIND_INTEGER,
	BIND_STRING,
} BindType;

class DBHelper
{
public:
	DBHelper();
	~DBHelper();

	bool isConnected() const;

	SQLRETURN bindCol(MdfEnum, BindType, void *);
	SQLRETURN bindParameter(MdfEnum, BindType, void *);
	SQLRETURN execute(MdfEnum, SQLWCHAR * = NULL);
	SQLRETURN prepare(MdfEnum, SQLWCHAR *);
	SQLRETURN fetch(MdfEnum);
	SQLRETURN cancel(MdfEnum);
	SQLRETURN getData(MdfEnum, SQLUSMALLINT, BindType, void *);
	void initializeBindCnt(MdfEnum);
	
	FNRETURN moveCursor(MdfEnum);
	SQLHSTMT &getStmt(MdfEnum);
private:
	static bool _isConnected;
	
	SQLUSMALLINT bindColCnt[MDF_COUNT] = {0};
	SQLUSMALLINT bindParameterCnt[MDF_COUNT] = {0};

	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];

	void connectDB();
	void closeDB();
};

#endif // !DB_HELPER_H