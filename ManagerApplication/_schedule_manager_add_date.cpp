#include "schedule_manager.h"
#include <vector>

void ScheduleManager::addDate()
{
	for (vector<Date> dateVector;;)
	{
		system("cls");
		cout << "추가한 날짜";
		for (size_t i = 0; i < dateVector.size(); i++)
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
			SQLBindParameter(dbHelper.getStmt(THEATER), 1, SQL_PARAM_INPUT, SQL_C_LONG, 
				SQL_INTEGER, sizeof(newDate.value), 0, &newDate.value, 0, NULL);
			
			if (SQLExecDirect(dbHelper.getStmt(THEATER),
				L"INSERT INTO schedule (date) VALUES (?);", SQL_NTS) == SQL_SUCCESS)
			{
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"SELECT * INTO d%d FROM sale_info;", newDate.value);
				SQLExecDirect(dbHelper.getStmt(SALE_INFO), sql, SQL_NTS);
				SQLCancel(dbHelper.getStmt(SALE_INFO));

				swprintf_s(sql, L"SELECT * INTO d%d FROM sales_record;", newDate.value);
				SQLExecDirect(dbHelper.getStmt(SALE_RECORD), sql, SQL_NTS);
				SQLCancel(dbHelper.getStmt(SALE_RECORD));

				dateVector.push_back(newDate);
			}

			SQLCancel(dbHelper.getStmt(THEATER));
		} 
	}
}