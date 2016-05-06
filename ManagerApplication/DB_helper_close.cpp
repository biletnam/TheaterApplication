#include "DB_helper.h"

bool DBHelper::closeDB()
{
	bool isClosed = true;
	SQLRETURN ret;

	for (int i = 0; i < MDF_COUNT; i++) {
		if (stmt[i] != SQL_NULL_HSTMT)
		{
			ret = SQLFreeHandle(SQL_HANDLE_STMT, stmt[i]);
		}
		if (dbc[i] != SQL_NULL_HDBC)
		{
			ret = SQLDisconnect(dbc[i]);
			ret = SQLFreeHandle(SQL_HANDLE_DBC, dbc[i]);
		}
	}
	if (env != SQL_NULL_HENV)
	{
		ret = SQLFreeHandle(SQL_HANDLE_ENV, env);
	}

	return isClosed;
}