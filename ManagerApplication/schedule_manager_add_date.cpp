#include "schedule_manager.h"

void ScheduleManager::addDate()
{
	for (;;)
	{
		Date date(dbHelper);
		inputDate(date);

		SQLWCHAR saleInfoSql[BUFSIZ];
		swprintf_s(saleInfoSql, L"SELECT * INTO d%d FROM sale_info;", date.getValue());

		SQLWCHAR saleRecordSql[BUFSIZ];
		swprintf_s(saleRecordSql, L"SELECT * INTO d%d FROM sales_record;", date.getValue());

		date.bindParameter();
		if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, L"INSERT INTO schedule (date) VALUES (?);")
			&& SQL_SUCCESS == dbHelper.execute(MDF_SALE_INFO, saleInfoSql)
			&& SQL_SUCCESS == dbHelper.execute(MDF_SALE_RECORD, saleRecordSql))
		{
			cout << "\n������ �߰��Ǿ����ϴ�.\n";
		}
		else
		{
			cout << "\n������ �߻��߽��ϴ�.(addDate)\n";
		}
		system("pause");
	}
}