#include "DB_helper.h"

bool DBHelper::closeDB()
{
	for (int i = 0; i < MDF_COUNT; i++) {
		if (!(stmt[i] != SQL_NULL_HSTMT
			&& SQLFreeHandle(SQL_HANDLE_STMT, stmt[i]) == SQL_SUCCESS
			&& dbc[i] != SQL_NULL_HDBC
			&& SQLDisconnect(dbc[i]) == SQL_SUCCESS
			&& SQLFreeHandle(SQL_HANDLE_DBC, dbc[i]) == SQL_SUCCESS))
		{
			return false;
		}
	}

	if (env != SQL_NULL_HENV
		&& SQLFreeHandle(SQL_HANDLE_ENV, env) == SQL_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}
}