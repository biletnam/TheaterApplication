#include "DBHelper.h"

bool DBHelper::closeDB()
{
	bool isClosed = false;

	for (int i = 0; i < MDF_COUNT; i++) {
		if (stmt[i] != SQL_NULL_HSTMT)
		{
			SQLFreeHandle(SQL_HANDLE_STMT, stmt[i]);
		}
		if (dbc[i] != SQL_NULL_HDBC)
		{
			SQLDisconnect(dbc[i]);
			SQLFreeHandle(SQL_HANDLE_DBC, dbc[i]);
		}
	}
	if (env != SQL_NULL_HENV)
	{
		SQLFreeHandle(SQL_HANDLE_ENV, env);
	}

	return true;
}