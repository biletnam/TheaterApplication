#include "DB_helper.h"


bool DBHelper::connectDB()
{
	SQLWCHAR connectingString[MDF_COUNT][BUFSIZ];
	SQLWCHAR mdf[MDF_COUNT][BUFSIZ];
	wcscpy_s(mdf[0], L"theater");		// ���� ����
	wcscpy_s(mdf[1], L"sale_info");		// �Ǹ� ����
	wcscpy_s(mdf[2], L"seat");			// �󿵰� �¼� ����
	wcscpy_s(mdf[3], L"sales_record");	// �Ǹ� ����
	SQLWCHAR* driver = L"DRIVER={SQL Server Native Client 11.0}";
	SQLWCHAR* server = L"Server=(localdb)\\MSSQLLocalDB";
	SQLWCHAR* trust = L"Trusted_Connection=yes";
	SQLWCHAR* currentDir = _wgetcwd(NULL, 0);
	*wcsrchr(currentDir, '\\') = 0;

	for (int i = 0; i < MDF_COUNT; i++)
	{
		wsprintf(connectingString[i], TEXT("%s;%s;%s;Database=%s\\%s.mdf;"),
			driver, server, trust, currentDir, mdf[i]);
	}
	
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);

	for (int i = 0; i < MDF_COUNT; i++)
	{
		SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc[i]);
		SQLDriverConnect(dbc[i], GetDesktopWindow(), connectingString[i],
			SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);
		SQLAllocHandle(SQL_HANDLE_STMT, dbc[i], &stmt[i]);
		if (SQLSetStmtAttr(stmt[i], SQL_ATTR_CURSOR_SCROLLABLE, (SQLPOINTER)SQL_SCROLLABLE, 0) != SQL_SUCCESS)
		{
			return false;
		}
	}

	theaterStmt = stmt[0];
	saleInfoStmt = stmt[1];
	seatStmt = stmt[2];
	salesRecordStmt = stmt[3];

	return true;
}