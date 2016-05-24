#include "DB_helper.h"

void DBHelper::closeDB()
{
	for (size_t i = 0; i < MDF_COUNT; i++) {
		SQLFreeHandle(SQL_HANDLE_STMT, stmt[i]);
		SQLDisconnect(dbc[i]);
		SQLFreeHandle(SQL_HANDLE_DBC, dbc[i]);
	}

	SQLFreeHandle(SQL_HANDLE_ENV, env);
}