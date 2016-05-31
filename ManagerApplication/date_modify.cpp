#include "date.h"

SQLRETURN Date::del()
{
	bindParameter();
	SQLWCHAR saleInfoSql[BUFSIZ];
	SQLWCHAR saleRecordSql[BUFSIZ];
	swprintf_s(saleInfoSql, L"DROP TABLE d%d;", value);
	swprintf_s(saleRecordSql, L"DROP TABLE d%d;", value);
	if (SQL_SUCCESS == execute(MDF_THEATER, L"DELETE FROM schedule WHERE date=?;")
		&& SQL_SUCCESS == execute(MDF_SALE_INFO, saleInfoSql)
		&& SQL_SUCCESS == execute(MDF_SALE_RECORD, saleRecordSql))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}

SQLRETURN Date::insert()
{
	bindParameter();
	SQLWCHAR saleInfoSql[BUFSIZ];
	SQLWCHAR saleRecordSql[BUFSIZ];
	swprintf_s(saleInfoSql, L"SELECT * INTO d%d FROM sale_info;", value);
	swprintf_s(saleRecordSql, L"SELECT * INTO d%d FROM sales_record;", value);

	// ¿Ö sql_no_data?
	if (SQL_SUCCESS == execute(MDF_THEATER, L"INSERT INTO schedule (date) VALUES (?);")
		&& SQL_NO_DATA == execute(MDF_SALE_INFO, saleInfoSql)
		&& SQL_NO_DATA == execute(MDF_SALE_RECORD, saleRecordSql))
	{
		return SQL_SUCCESS;
	}
	else
	{
		return SQL_ERROR;
	}
}
