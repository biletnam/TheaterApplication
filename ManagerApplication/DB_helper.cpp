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

void DBHelper::bindCol(SQLHSTMT &stmt, SQLUSMALLINT column, BIND_TYPE bindType, void *target)
{
	switch (bindType)
	{
	case INTEGER:
		SQLBindCol(stmt, column, SQL_INTEGER, target, sizeof(SQLINTEGER), NULL);
		break;
	case CHARACTER:
		SQLBindCol(stmt, column, SQL_WVARCHAR, target, BUFSIZ, NULL);
	}
}

void DBHelper::bindParameter(SQLHSTMT &stmt, SQLUSMALLINT column, BIND_TYPE bindType, void *target)
{
	switch (bindType)
	{
	case INTEGER:
		SQLBindParameter(stmt, column, SQL_PARAM_INPUT, SQL_C_LONG,
			SQL_INTEGER, sizeof(SQLINTEGER), 0, target, 0, NULL);
		break;
	case CHARACTER:
		SQLBindParameter(stmt, column, SQL_PARAM_INPUT, SQL_C_WCHAR,
			SQL_WVARCHAR, BUFSIZ, 0, target, 0, NULL);
	}
}

SQLHSTMT & DBHelper::getStmt(MDF_ENUM mdf)
{
	return stmt[mdf];
}