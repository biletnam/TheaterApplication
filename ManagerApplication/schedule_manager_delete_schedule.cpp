#include "schedule_manager.h"

void ScheduleManager::deleteSchedule(Schedule &schedule)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ��/����\n"
			"   > �� ���� ����\n"
			"\n"
			"������ �� ����\n";
		schedule.date.show();
		schedule.screen.show();
		schedule.show();

		cout << "\n�����Ͻðڽ��ϱ�?(y/n): ";
		switch (inputYN())
		{
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			SQLWCHAR scheduleSql[BUFSIZ];	// + priceSql
			swprintf_s(scheduleSql, L"DELETE FROM d%d WHERE id=%d;",
				schedule.date.getValue(), schedule.getId());

			SQLWCHAR priceSql[BUFSIZ];	// + priceSql
			swprintf_s(scheduleSql, L"DELETE FROM d%d WHERE schedule_id=%d;",
				schedule.date.getValue(), schedule.getId());

			SQLWCHAR seatSql[BUFSIZ];
			swprintf_s(seatSql, L"DROP TABLE d%ds%dt%d;", 
				schedule.date.getValue(), schedule.screen.getNumber(), schedule.getStartTime());

			// return �� Ȯ���ؾ� ��
			if (SQL_SUCCESS == schedule.execute(MDF_SCHEDULE, scheduleSql)
				&& SQL_SUCCESS == schedule.execute(MDF_PRICE, priceSql)
				&& SQL_SUCCESS == schedule.execute(MDF_SEAT, seatSql))
			{
				cout << "\n�����Ǿ����ϴ�.\n";
				system("pause");
			}
			else
			{
				cout << "\n������ �߻��߽��ϴ�.(deleteSchedule)\n";
				system("pause");
				break;
			}
		case FUNCTION_CANCEL:
			return;
		}

	}
}