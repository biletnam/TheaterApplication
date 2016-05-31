#include "schedule_manager.h"

void ScheduleManager::addDate()
{
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"극장 관리 시스템\n"
			" > 상영 일정 관리\n"
			"  > 상영일 추가\n";

		if (0 != date.getValue())
		{
			cout << "\n추가할 날짜: \n";
			date.show();
		}

		if(0 != date.getYear()
			&& 0 != date.getMonth()
			&& 0 != date.getDay())
		{
			SQLWCHAR saleInfoSql[BUFSIZ];
			swprintf_s(saleInfoSql, L"SELECT * INTO d%d FROM sale_info;", date.getValue());

			SQLWCHAR saleRecordSql[BUFSIZ];
			swprintf_s(saleRecordSql, L"SELECT * INTO d%d FROM sales_record;", date.getValue());

			date.bindParameter();
			if (SQL_SUCCESS == date.execute(MDF_THEATER, L"INSERT INTO schedule (date) VALUES (?);")
				&& SQL_SUCCESS == date.execute(MDF_SALE_INFO, saleInfoSql)
				&& SQL_SUCCESS == date.execute(MDF_SALE_RECORD, saleRecordSql))
			{
				cout << "\n상영일이 추가되었습니다.\n";
			}
			else
			{
				cout << "\n오류가 발생했습니다.(addDate)\n";
			}
			system("pause");
		}
		else if (FUNCTION_CANCEL == date.input())
		{
			return;
		}
	}
}