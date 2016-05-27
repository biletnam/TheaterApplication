#include "schedule_manager.h"

void ScheduleManager::addDate()
{
	for (;;)
	{
		Date date;

		for (;;)
		{
			system("cls");
			cout <<
				"극장 관리 시스템\n"
				" > 상영 일정 관리\n"
				"  > 상영일 추가\n"
				"\n"
				"추가할 날짜: ";
			date.show();
			cout << endl;

			// 연도 입력
			// 월 입력
			// 일 입력
			
			if (0 != date.getDay())
			{
				break;
			}
			else if (0 == date.getYear()
				&& FUNCTION_CANCEL == date.inputYear())
			{
				return;
			}
			else if (0 == date.getMonth()
				&& FUNCTION_CANCEL == date.inputMonth())
			{
				date.setYear(0);
			}
			else if(FUNCTION_CANCEL == date.inputDay())
			{
				date.setMonth(0);
			}
		}

		SQLWCHAR saleInfoSql[BUFSIZ];
		swprintf_s(saleInfoSql, L"SELECT * INTO d%d FROM sale_info;", date.value);

		SQLWCHAR saleRecordSql[BUFSIZ];
		swprintf_s(saleRecordSql, L"SELECT * INTO d%d FROM sales_record;", date.value);

		dbHelper.bindParameter(MDF_THEATER, BIND_INTEGER, &date.value);
		if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, L"INSERT INTO schedule (date) VALUES (?);")
			&& SQL_SUCCESS == dbHelper.execute(MDF_SALE_INFO, saleInfoSql)
			&& SQL_SUCCESS == dbHelper.execute(MDF_SALE_RECORD, saleRecordSql))
		{
			cout << "\n상영일이 추가되었습니다.\n";
		}
		else
		{
			cout << "\n오류가 발생했습니다.(addDate)\n";
		}
		system("pause");
	}
}