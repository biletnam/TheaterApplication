#include "DB_helper.h"

SQLRETURN DBHelper::bindCol(MdfEnum mdf, BindType bindType, void *target)
{
	if (SQL_SUCCESS == cancel(mdf))
	{
		switch (bindType)
		{
		case BIND_INTEGER:
			return SQLBindCol(stmt[mdf], ++bindColCnt[mdf], SQL_INTEGER, target, sizeof(SQLINTEGER), NULL);
		case BIND_STRING:
			return SQLBindCol(stmt[mdf], ++bindColCnt[mdf], SQL_CHAR, target, BUFSIZ, NULL);
		}
	}
	
	return SQL_ERROR;
}

SQLRETURN DBHelper::bindParameter(MdfEnum mdf, BindType bindType, void *target)
{
	if (SQL_SUCCESS == cancel(mdf))
	{
		switch (bindType)
		{
		case BIND_INTEGER:
			return SQLBindParameter(stmt[mdf], ++bindParameterCnt[mdf], SQL_PARAM_INPUT, SQL_C_LONG,
				SQL_INTEGER, sizeof(SQLINTEGER), 0, target, 0, NULL);
		case BIND_STRING:
			return SQLBindParameter(stmt[mdf], ++bindParameterCnt[mdf], SQL_PARAM_INPUT, SQL_C_WCHAR,
				SQL_WVARCHAR, BUFSIZ, 0, target, 0, NULL);
		}
	}
	
	return SQL_ERROR;
}

SQLRETURN DBHelper::getData(MdfEnum mdf, SQLUSMALLINT column, BindType bindType, void *target)
{
	if (SQL_SUCCESS == SQLFreeStmt(stmt[mdf], SQL_UNBIND))
	{
		switch (bindType)
		{
		case BIND_INTEGER:
			return SQLGetData(stmt[mdf], column, SQL_INTEGER, target, sizeof(SQLINTEGER), NULL);
		case BIND_STRING:
			return SQLGetData(stmt[mdf], column, SQL_CHAR, target, BUFSIZ, NULL);
		}
	}

	return SQL_ERROR;
}

SQLRETURN DBHelper::execute(MdfEnum mdf, SQLWCHAR *sql)
{
	if (sql != NULL)
	{
		prepare(mdf, sql);
	}
	initializeBindCnt(mdf);

	return SQLExecute(stmt[mdf]);
}

SQLRETURN DBHelper::prepare(MdfEnum mdf, SQLWCHAR *sql)
{
	cancel(mdf);
	return SQLPrepare(stmt[mdf], sql, SQL_NTS);
}

SQLRETURN DBHelper::fetch(MdfEnum mdf)
{
	return SQLFetch(stmt[mdf]);
}

SQLRETURN DBHelper::cancel(MdfEnum mdf)
{
	if (0 == bindColCnt[mdf] && 0 == bindParameterCnt[mdf])
	{
		return SQLCancel(stmt[mdf]);
	}
	else
	{
		return SQL_SUCCESS;
	}
}

void DBHelper::initializeBindCnt(MdfEnum mdf)
{
	bindColCnt[mdf] = 0;
	bindParameterCnt[mdf] = 0;
}

SQLHSTMT & DBHelper::getStmt(MdfEnum mdf)
{
	return stmt[mdf];
}