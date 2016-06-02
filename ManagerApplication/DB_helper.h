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
	MDF_SCHEDULE,
	MDF_PRICE,
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
	static FNRETURN connectDB();
	static void closeDB();

	FNRETURN showSelectResult(MdfEnum);
	FNRETURN choose(MdfEnum);
	FNRETURN moveCursor(MdfEnum);

	virtual void show() = 0;
	virtual void initialize() = 0;
	void initializeBindCnt(MdfEnum);

	SQLRETURN bindCol(MdfEnum, BindType, void *);
	SQLRETURN bindParameter(MdfEnum, BindType, void *);
	SQLRETURN execute(MdfEnum, SQLWCHAR * = NULL);
	SQLRETURN prepare(MdfEnum, SQLWCHAR *);
	SQLRETURN fetch(MdfEnum);
	SQLRETURN cancel(MdfEnum);
private:
	static SQLUSMALLINT bindColCnt[MDF_COUNT];
	static SQLUSMALLINT bindParameterCnt[MDF_COUNT];

	static SQLHENV env;
	static SQLHDBC dbc[MDF_COUNT];
	static SQLHSTMT stmt[MDF_COUNT];
};

#endif // !DB_HELPER_H