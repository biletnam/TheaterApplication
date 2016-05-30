#include "schedule_manager.h"

void ScheduleManager::checkAndDeleteDate()
{
	Date date(dbHelper);

	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > ���� Ȯ��/����\n"
			"\n";

		if (0 != date.getValue())
		{

		}
		
		Date::today(dbHelper).bindParameter();
		if (SQL_SUCCESS != dbHelper.execute(MDF_THEATER, L"SELECT date FROM schedule WHERE date>?;"))
		{
			cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
			system("pause");
			return;
		}

		switch (date.showSelectResult())
		{
		case FUNCTION_SUCCESS:
			cout <<
				"0. ����\n"
				"\n"
				"������ ������ �����ϼ���: ";
			switch (dbHelper.moveCursor(MDF_THEATER))
			{
			case FUNCTION_ERROR:
				cout << "\n������ �߻��߽��ϴ�(checkAndDeletedate).\n";
				system("pause");
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
				cout << "\n�����Ǿ����ϴ�.\n";
				system("pause");
			}
		case FUNCTION_ERROR:
		case FUNCTION_NULL:
		default:
			break;
		}

/*		for (size_t i = 1;; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				date.show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "��ϵ� ������ �����ϴ�\n";
				}
				else
				{
					cout << 
						"0. ����\n"
						"\n"
						"������ ������ �����ϼ���: ";
					switch (dbHelper.moveCursor(MDF_THEATER))
					{
					case FUNCTION_ERROR:
						cout << "\n������ �߻��߽��ϴ�(checkSchedule).\n";
						system("pause");
					case FUNCTION_CANCEL:
						return;
					case FUNCTION_SUCCESS:
						cout << "\n�����Ǿ����ϴ�.\n";
						system("pause");
					}
				}
			}
			break;
		}*/
	}
}