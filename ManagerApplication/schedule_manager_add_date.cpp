#include "schedule_manager.h"
#include <vector>

void ScheduleManager::addDate()
{
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 확인/삭제\n"
			"\n";

		Date date;
		if (date.choose() == false)
		{
			return;
		} 
		else
		{
			date.show();
			cout << endl;

			SQLCancel(dbHelper.getStmt(MDF_THEATER));
			SQLBindParameter(dbHelper.getStmt(MDF_THEATER), 1, SQL_PARAM_INPUT, SQL_C_LONG, 
				SQL_INTEGER, sizeof date.value, 0, &date.value, 0, NULL);
			
			if (SQL_SUCCESS ==
				SQLExecDirect(dbHelper.getStmt(MDF_THEATER), L"INSERT INTO schedule (date) VALUES (?);", SQL_NTS))
			{
				SQLWCHAR saleInfoSql[BUFSIZ];
				swprintf_s(saleInfoSql, L"SELECT * INTO d%d FROM sale_info;", date.value);
				SQLCancel(dbHelper.getStmt(MDF_SALE_INFO));
				SQLExecDirect(dbHelper.getStmt(MDF_SALE_INFO), saleInfoSql, SQL_NTS);

				SQLWCHAR saleRecordSql[BUFSIZ];
				swprintf_s(saleRecordSql, L"SELECT * INTO d%d FROM sales_record;", date.value);
				SQLCancel(dbHelper.getStmt(MDF_SALE_RECORD));
				SQLExecDirect(dbHelper.getStmt(MDF_SALE_RECORD), saleRecordSql, SQL_NTS);
			}
		} 
	}
}