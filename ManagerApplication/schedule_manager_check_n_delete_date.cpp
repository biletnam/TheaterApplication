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
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"DROP TABLE d%d;", date.getValue());
				if (SQL_SUCCESS == date.bindParameter()
					&& SQL_SUCCESS == date.execute(MDF_THEATER, L"DELETE FROM date WHERE date_value=?;")
					&& SQL_SUCCESS == date.execute(MDF_SCHEDULE, sql)
					&& SQL_SUCCESS == date.execute(MDF_PRICE, sql)
					&& SQL_SUCCESS == date.execute(MDF_SALES, sql))
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
			if (SQL_SUCCESS != Date::getToday().bindParameter()
				|| SQL_SUCCESS != date.bindCol()
				|| SQL_SUCCESS != date.prepare(MDF_THEATER, L"SELECT date_value FROM date WHERE date_value>?;"))
			{
				cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
				system("pause");
				return;
			}
			
			switch (date.choose(MDF_THEATER))
			{
			case FUNCTION_ERROR:
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_NULL:
				cout << "��ϵ� �� �������� �����ϴ�\n";
				system("pause");
			}
		}
	}
}