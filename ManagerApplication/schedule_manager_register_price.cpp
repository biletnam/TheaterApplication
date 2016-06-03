#include "schedule_manager.h"

void ScheduleManager::registerPrice(Schedule &schedule)
{
	for (Price price;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ��/����\n"
			"   > ���� ���\n\n"

			"������ �� ����\n";
		schedule.show();
		
		if (0 < price.getCode())
		{
			cout << "\n������ ���� ����\n";
			price.show();

			cout << "\n����Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				SQLWCHAR sql[BUFSIZ];
				swprintf_s(sql, L""
					"INSERT INTO d%d "
					"(schedule_id, code, name, won) "
					"VALUES (%d, ?, ?, ?);", schedule.date.getValue(), schedule.getId());
				if (SQL_SUCCESS == price.bindParameter(MDF_PRICE)
					&& SQL_SUCCESS == price.execute(MDF_PRICE, sql))
				{
					cout << "\n��ϵǾ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(registerPrice)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				price.initialize();
			}
		}
		else
		{
			if (SQL_SUCCESS != price.bindCol(MDF_THEATER)
				|| SQL_SUCCESS != price.prepare(MDF_THEATER, L"SELECT code, name, won FROM price;"))
			{
				cout << "������ �߻��߽��ϴ�.(registerPrice)\n";
				system("pause");
				return;
			}

			switch (price.choose(MDF_THEATER))
			{
			case FUNCTION_NULL:
				cout << "��ϵ� ���� ������ �����ϴ�.\n";
				system("pause");
			case FUNCTION_ERROR:
			case FUNCTION_CANCEL:
				return;
			}
		}
	}
}
