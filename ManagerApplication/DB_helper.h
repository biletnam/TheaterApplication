#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "common_header.h"

enum MdfEnum
{
	MDF_THEATER,
	MDF_SCHEDULE,
	MDF_PRICE,
	MDF_SEAT,
	MDF_SALES,
	MDF_COUNT
};

enum BindType
{
	BIND_INTEGER,
	BIND_STRING,
};

class DBHelper
{
public:
	virtual void show() const = 0;
	virtual void initialize() = 0;

	static FNRETURN connectDB();
	static void closeDB();

	FNRETURN showSelectResult(MdfEnum);
	FNRETURN choose(MdfEnum);
	FNRETURN moveCursor(MdfEnum);
	
	void initializeBindCnt(MdfEnum);
	SQLRETURN bindCol(MdfEnum, BindType, void *);
	SQLRETURN bindParameter(MdfEnum, BindType, void *);
	SQLRETURN execute(MdfEnum, SQLWCHAR * = NULL);
	SQLRETURN prepare(MdfEnum, SQLWCHAR *);
	SQLRETURN fetch(MdfEnum);
private:
	static SQLHENV env;
	static SQLHDBC dbc[MDF_COUNT];
	static SQLHSTMT stmt[MDF_COUNT];
	static SQLUSMALLINT bindColCnt[MDF_COUNT];
	static SQLUSMALLINT bindParameterCnt[MDF_COUNT];

	SQLRETURN cancel(MdfEnum);
};

#endif // !DB_HELPER_H