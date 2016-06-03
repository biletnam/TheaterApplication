#include "schedule_manager.h"

void ScheduleManager::setScreen(Screen &screen)
{
	system("cls");
	cout <<
		"���� ���� �ý���\n"
		" > �� ���� ����\n"
		"  > �� ���� ���\n"
		"   > �󿵰� ����\n";

	if (SQL_SUCCESS != screen.prepare(MDF_THEATER, L"SELECT number, row, col FROM screen;")
		|| SQL_SUCCESS != screen.bindCol())
	{
		cout << "\n������ �߻��߽��ϴ�(setScreen).\n";
		system("pause");
	}
	else if (FUNCTION_NULL == screen.choose(MDF_THEATER))
	{
		cout << "\n��� ������ �󿵰��� �����ϴ�\n";
		system("pause");
	}
}