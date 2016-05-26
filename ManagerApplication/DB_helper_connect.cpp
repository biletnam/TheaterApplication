#include "DB_helper.h"

void DBHelper::connectDB()
{
	SQLWCHAR connectingString[MDF_COUNT][BUFSIZ];
	SQLWCHAR mdf[MDF_COUNT][BUFSIZ];
	wcscpy_s(mdf[MDF_THEATER], L"theater");				// 극장 정보
	wcscpy_s(mdf[MDF_SALE_INFO], L"sale_info");			// 판매 정보
	wcscpy_s(mdf[MDF_SEAT], L"seat");					// 상영관 좌석 정보
	wcscpy_s(mdf[MDF_SALE_RECORD], L"sales_record");	// 판매 내역
	SQLWCHAR* driver = L"DRIVER={SQL Server Native Client 11.0}";
	SQLWCHAR* server = L"Server=(localdb)\\MSSQLLocalDB";
	SQLWCHAR* trust = L"Trusted_Connection=yes";
	SQLWCHAR* currentDir = _wgetcwd(NULL, 0);
	*wcsrchr(currentDir, '\\') = 0;

	for (size_t i = 0; i < MDF_COUNT; i++)
	{
		wsprintf(connectingString[i], TEXT("%s;%s;%s;Database=%s\\%s.mdf;"),
			driver, server, trust, currentDir, mdf[i]);
	}
	
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);

	for (size_t i = 0; i < MDF_COUNT; i++)
	{
		SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc[i]);
		SQLDriverConnect(dbc[i], GetDesktopWindow(), connectingString[i],
			SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);
		SQLAllocHandle(SQL_HANDLE_STMT, dbc[i], &stmt[i]);
		if (SQLSetStmtAttr(stmt[i], SQL_ATTR_CURSOR_SCROLLABLE, (SQLPOINTER)SQL_SCROLLABLE, 0)
			!= SQL_SUCCESS)
		{
			return;
		}
	}

	_isConnected = true;
}