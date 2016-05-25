#ifndef DB_HELPER_H
#define DB_HELPER_H

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "common_header.h"

typedef enum MDF_ENUM
{
	THEATER,
	SALE_INFO,
	SEAT,
	SALE_RECORD,
	MDF_COUNT
};

class DBHelper
{
public:
	DBHelper();
	~DBHelper();

	bool isConnected() const;
	
	FNRETURN moveCursor(SQLHSTMT&, const char*);
	SQLHSTMT &getStmt(MDF_ENUM);
private:
	static bool _isConnected;

	SQLHENV env;
	SQLHDBC dbc[MDF_COUNT];
	SQLHSTMT stmt[MDF_COUNT];

	void connectDB();
	void closeDB();
};

#endif // !DB_HELPER_H