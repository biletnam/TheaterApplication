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
	cancel(mdf);
	switch (bindType)
	{
	case BIND_INTEGER:
		return SQLBindCol(stmt[mdf], ++bindColCnt[mdf], SQL_INTEGER, target, sizeof(SQLINTEGER), NULL);
	case BIND_STRING:
		return SQLBindCol(stmt[mdf], ++bindColCnt[mdf], SQL_CHAR, target, BUFSIZ, NULL);
	}

	return SQLRETURN();
}

SQLRETURN DBHelper::bindParameter(MDF_ENUM mdf, BIND_TYPE bindType, void *target)
{
	cancel(mdf);
	switch (bindType)
	{
	case BIND_INTEGER:
		return SQLBindParameter(stmt[mdf], ++bindParameterCnt[mdf], SQL_PARAM_INPUT, SQL_C_LONG,
			SQL_INTEGER, sizeof(SQLINTEGER), 0, target, 0, NULL);
	case BIND_STRING:
		return SQLBindParameter(stmt[mdf], ++bindParameterCnt[mdf], SQL_PARAM_INPUT, SQL_C_WCHAR,
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
	initializeBindCnt(mdf);

	return SQLExecute(stmt[mdf]);
}

SQLRETURN DBHelper::prepare(MDF_ENUM mdf, SQLWCHAR *sql)
{
	cancel(mdf);
	return SQLPrepare(stmt[mdf], sql, SQL_NTS);
}

SQLRETURN DBHelper::fetch(MDF_ENUM mdf)
{
	return SQLFetch(stmt[mdf]);
}

SQLRETURN DBHelper::cancel(MDF_ENUM mdf)
{
	if (0 == bindColCnt[mdf] && 0 == bindParameterCnt[mdf])
	{
		return SQLCancel(stmt[mdf]);
	}
	return SQLRETURN();
}

SQLRETURN DBHelper::getData(MDF_ENUM mdf, SQLUSMALLINT column, BIND_TYPE bindType, void *target)
{
	SQLFreeStmt(stmt[mdf], SQL_UNBIND);

	switch (bindType)
	{
	case BIND_INTEGER:
		return SQLGetData(stmt[mdf], column, SQL_INTEGER, target, sizeof(SQLINTEGER), NULL);
	case BIND_STRING:
		return SQLGetData(stmt[mdf], column, SQL_CHAR, target, BUFSIZ, NULL);
	}
	
	return SQLRETURN();
}

void DBHelper::initializeBindCnt(MDF_ENUM mdf)
{
	bindColCnt[mdf] = 0;
	bindParameterCnt[mdf] = 0;
}

SQLHSTMT & DBHelper::getStmt(MDF_ENUM mdf)
{
	return stmt[mdf];
}