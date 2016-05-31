#include "schedule_manager.h"

void ScheduleManager::addDate()
{
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
			cout << "\n�߰��� ��¥: \n";
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
				cout << "\n������ �߰��Ǿ����ϴ�.\n";
			}
			else
			{
				cout << "\n������ �߻��߽��ϴ�.(addDate)\n";
			}
			system("pause");
		}
		else if (FUNCTION_CANCEL == date.input())
		{
			return;
		}
	}
}