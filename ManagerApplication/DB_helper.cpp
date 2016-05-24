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

SQLHSTMT & DBHelper::getStmt(MDF_ENUM mdf)
{
	return stmt[mdf];
}