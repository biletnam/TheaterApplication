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
				"���� ���� �ý���\n"
				" > �� ���� ����\n"
				"  > ���� �߰�\n"
				"\n"
				"�߰��� ��¥: ";
			date.show();
			cout << endl;

			// ���� �Է�
			// �� �Է�
			// �� �Է�
			
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
			cout << "\n������ �߰��Ǿ����ϴ�.\n";
		}
		else
		{
			cout << "\n������ �߻��߽��ϴ�.(addDate)\n";
		}
		system("pause");
	}
}