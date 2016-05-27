#include "schedule_manager.h"

FNRETURN ScheduleManager::inputDate(Date &date)
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

	if (0 != date.getDay())
	{
		return FUNCTION_SUCCESS;
	}
	else if (0 == date.getYear())
	{
		cout << "������ �Է��ϼ���(0�� �Է��ϸ� ����):";

		if (false == date.setYear(inputInteger()))
		{
			cout << "\n�߸��� �Է��Դϴ�.(0���� ũ�ų� ���� ������ �Է��ϼ���)\n";
			system("pause");
		}
		else if (0 == date.getYear())
		{
			return FUNCTION_CANCEL;
		}
	}
	else if (0 == date.getMonth())
	{
		cout << "���� �Է��ϼ���(0�� �Է��ϸ� ����):";

		if (false == date.setMonth(inputInteger()))
		{
			cout << "\n�߸��� �Է��Դϴ�.(0~12 ������ ������ �Է��ϼ���)\n";
			system("pause");
		}
		else if (0 == date.getMonth())
		{
			date.setYear(0);
		}
	}
	else
	{
		cout << "���� �Է��ϼ���(0�� �Է��ϸ� ����):";

		if (false == date.setMonth(inputInteger()))
		{
			cout << "\n�߸��� �Է��Դϴ�.(0~" << date.getLastDay() << " ������ ������ �Է��ϼ���)\n";
			system("pause");
		}
		else if (0 == date.getDay())
		{
			date.setMonth(0);
		}
	}

	return inputDate(date);
}