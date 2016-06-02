#include "schedule_manager.h"

void ScheduleManager::checkAndDeletePrice(Schedule &schedule)
{
	for (Price price;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ��/����\n"
			"   > ���� ���� Ȯ��/����\n"
			"\n"
			"������ �� ����\n";
		schedule.show();
		cout << endl;

		if (0 < price.getCode())
		{
			cout << "\n������ ���� ����\n";
			price.show();

			cout << "\n�����Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L"DELETE FROM d%d WHERE shedule_id=%d AND code=%d;", 
					schedule.date.getValue(), schedule.getId(), price.getCode());
				if (SQL_SUCCESS == price.execute(MDF_PRICE, sql))
				{
					cout << "\n�����Ǿ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(checkAndDeletePrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else
		{
			SQLWCHAR sql[BUFSIZ];
			swprintf_s(sql, L"SELECT code, name, won FROM d%d WHERE schedule_id=%d;"
				, schedule.date.getValue(), schedule.getId());
			if (SQL_SUCCESS != price.bindCol(MDF_PRICE)
				|| SQL_SUCCESS != price.prepare(MDF_PRICE, sql))
			{
				cout << "������ �߻��߽��ϴ�.(checkAndDeletePrice)\n";
				system("pause");
				return;
			}

			switch (price.choose(MDF_PRICE))
			{
			case FUNCTION_NULL:
				cout << "��ϵ� ���� ������ �����ϴ�.\n";
				system("pause");
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
			case FUNCTION_ERROR:
				break;
			}
		}
	}
}