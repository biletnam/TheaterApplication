#include "schedule_manager.h"
#include <vector>

void ScheduleManager::addDate()
{
	for (vector<Date> dateVector;;)
	{
		system("cls");
		cout << "추가한 날짜";
		for (int i = 0; i < dateVector.size(); i++)
		{
			dateVector.at(i).show();
			cout << endl;
		}
		cout << endl;

		Date newDate;
		if (newDate.choose() == false)
		{
			return;
		} 
		else
		{
			SQLBindParameter(dbHelper.theaterStmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, 
				SQL_INTEGER, sizeof(newDate.value), 0, &newDate.value, 0, NULL);
			
			if (SQLExecDirect(dbHelper.theaterStmt,
				L"INSERT INTO schedule (date) VALUES (?);", SQL_NTS) == SQL_SUCCESS)
			{
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"SELECT * INTO d%d FROM sale_info;", newDate.value);
				SQLExecDirect(dbHelper.saleInfoStmt, sql, SQL_NTS);
				SQLCancel(dbHelper.saleInfoStmt);

				swprintf_s(sql, L"SELECT * INTO d%d FROM sales_record;", newDate.value);
				SQLExecDirect(dbHelper.salesRecordStmt, sql, SQL_NTS);
				SQLCancel(dbHelper.salesRecordStmt);

				dateVector.push_back(newDate);
			}

			SQLCancel(dbHelper.theaterStmt);
		} 
	}
}