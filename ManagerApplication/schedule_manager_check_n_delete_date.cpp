#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	Date date;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ��/����\n";

		if (0 < date.getValue())
		{
			cout << "\n������ ��¥ ����:\n";
			date.show();

			cout << "\n�����Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				date.bindParameter();
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"DROP TABLE d%d;", date.getValue());
				if (SQL_SUCCESS == date.execute(MDF_THEATER, L"DELETE FROM schedule WHERE date=?;")
					&& SQL_SUCCESS == date.execute(MDF_SCHEDULE, sql)
					&& SQL_SUCCESS == date.execute(MDF_PRICE, sql)
					&& SQL_SUCCESS == date.execute(MDF_SALE_RECORD, sql))
				{
					cout << "\n�����Ǿ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(checkAndDeleteDate)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				date.initialize();
			}
		}
		else
		{
			Date::getToday().bindParameter();
			if (SQL_SUCCESS != date.prepare(L"SELECT date FROM date WHERE date_value>?;"))
			{
				cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
				system("pause");
				return;
			}

			date.bindCol();
			switch (date.choose())
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "��ϵ� �� �������� �����ϴ�\n";
				system("pause");
			}
		}
	}
}