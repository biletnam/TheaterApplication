#include "schedule_manager.h"

void ScheduleManager::setScreen(Screen &screen)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� ���\n"
			"   > �󿵰� ����\n"
			"\n";

		switch (screen.choose())
		{
		case FUNCTION_ERROR:
			cout << "�߸��� �Է��Դϴ�.";
			system("pause");
			break;
		case FUNCTION_NULL:
			cout << "��� ������ �󿵰��� �����ϴ�\n";
			system("pause");
		case FUNCTION_SUCCESS:
		case FUNCTION_CANCEL:
			return;
		}
	}
}