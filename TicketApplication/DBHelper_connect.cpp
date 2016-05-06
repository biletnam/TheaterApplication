#include "DBHelper.h"

bool DBHelper::connectDB()
{
	bool isConnected = true;

	SQLWCHAR connectingString[MDF_COUNT][BUFSIZ];
	SQLWCHAR* driver = TEXT("DRIVER={SQL Server Native Client 11.0}");
	SQLWCHAR* server = TEXT("Server=(localdb)\\MSSQLLocalDB");
	SQLWCHAR* trust = TEXT("Trusted_Connection=yes");
	SQLWCHAR* currentDir = _wgetcwd(NULL, 0);
	*wcsrchr(currentDir, '\\') = 0;

	// 극장 정보
	wsprintf(connectingString[0], TEXT("%s;%s;%s;Database=%s\\theater.mdf;"),
		driver, server, trust, currentDir);
	// 상영 정보
	wsprintf(connectingString[1], TEXT("%s;%s;%s;Database=%s\\sale_info.mdf;"),
		driver, server, trust, currentDir);
	// 상영관 좌석 정보
	wsprintf(connectingString[2], TEXT("%s;%s;%s;Database=%s\\seat.mdf;"),
		driver, server, trust, currentDir);
	// 판매 내역
	wsprintf(connectingString[3], TEXT("%s;%s;%s;Database=%s\\sales_record.mdf;"),
		driver, server, trust, currentDir);

	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);

	for (int i = 0; i < MDF_COUNT; i++)
	{
		SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc[i]);
		SQLDriverConnect(dbc[i], GetDesktopWindow(), connectingString[i],
			SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);
		SQLAllocHandle(SQL_HANDLE_STMT, dbc[i], &stmt[i]);
		SQLRETURN ret = SQLSetStmtAttr(stmt[i], SQL_ATTR_CURSOR_SCROLLABLE, (SQLPOINTER)SQL_SCROLLABLE, 0);
		if (ret != SQL_SUCCESS)
		{
			isConnected = false;
		}
	}

	theaterStmt = stmt[0];
	saleInfoStmt = stmt[1];
	seatStmt = stmt[2];
	salesRecordStmt = stmt[3];

	return isConnected;
}