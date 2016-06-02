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
			cout << "\n추가할 날짜 정보: \n";
			date.show();
		}

		if (0 != date.get(DATE_YEAR)
			&& 0 != date.get(DATE_MONTH)
			&& 0 != date.get(DATE_DAY))
		{
			cout << "\n추가하시겠습니까?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n잘못된 입력입니다.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				date.bindParameter();
				SQLWCHAR scheduleSql[BUFSIZ];
				SQLWCHAR saleInfoSql[BUFSIZ];
				SQLWCHAR saleRecordSql[BUFSIZ];
				swprintf_s(scheduleSql, L"SELECT * INTO d%d FROM schedule;", date.getValue());
				swprintf_s(saleInfoSql, L"SELECT * INTO d%d FROM sale_info;", date.getValue());
				swprintf_s(saleRecordSql, L"SELECT * INTO d%d FROM sales_record;", date.getValue());
				if (SQL_SUCCESS == date.execute(MDF_THEATER, L"INSERT INTO schedule (date) VALUES (?);")
					&& SQL_NO_DATA == date.execute(MDF_SCHEDULE, scheduleSql)
					&& SQL_NO_DATA == date.execute(MDF_PRICE, saleInfoSql)
					&& SQL_NO_DATA == date.execute(MDF_SALE_RECORD, saleRecordSql))
				{
					cout << "\n추가되었습니다.\n";
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(addDate)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else if (FUNCTION_CANCEL == date.input())
		{
			return;
		}
	}
}