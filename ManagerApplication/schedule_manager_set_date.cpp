#include "schedule_manager.h"

void ScheduleManager::setDate(Date &date)
{
	system("cls");
	cout <<
		"���� ���� �ý���\n"
		" > �� ���� ����\n"
		"  > �� ���� ���\n"
		"   > ��¥ ����\n";

	if (SQL_SUCCESS != date.prepare(MDF_THEATER, L"SELECT date_value FROM date;")
		|| SQL_SUCCESS != date.bindCol())
	{
		cout << "\n������ �߻��߽��ϴ�(setDate).\n";
		system("pause");
	}
	else if (FUNCTION_NULL == date.choose(MDF_THEATER))
	{
		cout << "\n��� ������ ������ �����ϴ�\n";
		system("pause");
	}
}