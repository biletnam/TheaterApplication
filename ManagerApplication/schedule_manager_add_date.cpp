#include "schedule_manager.h"

void ScheduleManager::addDate()
{
	SQLRETURN ret;
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� �߰�\n";

		if (0 != date.getValue())
		{
			cout << "\n�߰��� ��¥ ����: \n";
			date.show();
		}

		if (0 != date.get(DATE_YEAR)
			&& 0 != date.get(DATE_MONTH)
			&& 0 != date.get(DATE_DAY))
		{
			cout << "\n�߰��Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				SQLWCHAR scheduleSql[BUFSIZ];
				SQLWCHAR priceSql[BUFSIZ];
				SQLWCHAR salesSql[BUFSIZ];
				swprintf_s(scheduleSql, L"SELECT * INTO d%d FROM schedule;", date.getValue());
				swprintf_s(priceSql, L"SELECT * INTO d%d FROM price;", date.getValue());
				swprintf_s(salesSql, L"SELECT * INTO d%d FROM sales;", date.getValue());

				if (SQL_SUCCESS == date.bindParameter()
					&& SQL_SUCCESS == date.execute(MDF_THEATER, L"INSERT INTO date (date_value) VALUES (?);")
					&& SQL_ERROR != date.execute(MDF_SCHEDULE, scheduleSql)
					&& SQL_ERROR != date.execute(MDF_PRICE, priceSql)
					&& SQL_ERROR != date.execute(MDF_SALES, salesSql))
				{
					cout << "\n�߰��Ǿ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(addDate)\n";
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