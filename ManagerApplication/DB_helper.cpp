#include "DB_helper.h"

DBHelper::DBHelper()
{
	if (_isConnected == false)
	{
		connectDB();
	}
}

DBHelper::~DBHelper()
{
	closeDB();
}

bool DBHelper::_isConnected = false;

bool DBHelper::isConnected() const
{
	return _isConnected;
}

SQLRETURN DBHelper::bindCol(MDF_ENUM mdf, BIND_TYPE bindType, void *target)
{
	if (0 == bindColCnt && 0 == bindParameterCnt)
	{
		SQLCancel(stmt[mdf]);
	}

	switch (bindType)
	{
	case BIND_INTEGER:
		return SQLBindCol(stmt[mdf], ++bindColCnt, SQL_INTEGER, target, sizeof(SQLINTEGER), NULL);
	case BIND_STRING:
		return SQLBindCol(stmt[mdf], ++bindColCnt, SQL_CHAR, target, BUFSIZ, NULL);
	}

	return SQLRETURN();
}

SQLRETURN DBHelper::bindParameter(MDF_ENUM mdf, BIND_TYPE bindType, void *target)
{
	if (0 == bindColCnt && 0 == bindParameterCnt)
	{
		SQLCancel(stmt[mdf]);
	}
	
	switch (bindType)
	{
	case BIND_INTEGER:
		return SQLBindParameter(stmt[mdf], ++bindParameterCnt, SQL_PARAM_INPUT, SQL_C_LONG,
			SQL_INTEGER, sizeof(SQLINTEGER), 0, target, 0, NULL);
	case BIND_STRING:
		return SQLBindParameter(stmt[mdf], ++bindParameterCnt, SQL_PARAM_INPUT, SQL_C_WCHAR,
			SQL_WVARCHAR, BUFSIZ, 0, target, 0, NULL);
	}

	return SQLRETURN();
}

SQLRETURN DBHelper::execute(MDF_ENUM mdf, SQLWCHAR *sql)
{
	if (sql != NULL)
	{
		prepare(mdf, sql);
	}
	initializeBindCnt();

	return SQLExecute(stmt[mdf]);
}

SQLRETURN DBHelper::prepare(MDF_ENUM mdf, SQLWCHAR *sql)
{
	if (0 == bindColCnt && 0 == bindParameterCnt)
	{
		SQLCancel(stmt[mdf]);
	}

	return SQLPrepare(stmt[mdf], sql, SQL_NTS);
}

void DBHelper::initializeBindCnt()
{
	bindColCnt = 0;
	bindParameterCnt = 0;
}

SQLHSTMT & DBHelper::getStmt(MDF_ENUM mdf)
{
	return stmt[mdf];
}