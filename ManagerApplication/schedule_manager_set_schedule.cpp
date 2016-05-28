#include "schedule_manager.h"

enum ScheduleManagerFunction
{
	CHOOSE_SCREEN = 1,
	CHOOSE_DATE,
	CHOOSE_MOVIE,
	INPUT_TIME,
	REGISTER_SCHEDULE,
};

FNRETURN ScheduleManager::setSchedule(Schedule & schedule)
{
	system("cls");
	cout <<
		"���� ���� �ý���\n"
		" > �� ���� ����\n"
		"  > �� ���� ���\n"
		"\n"
		"�� ������\n";
	schedule.showInfo();

	cout <<
		"1. �󿵰� ����\n"
		"2. ��¥ ����\n"
		"3. ��ȭ ����\n"
		"4. �ð� ����\n"
		"5. �� ������ ���\n"
		"0. ����\n";

	switch (inputInteger())
	{
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	case CHOOSE_SCREEN:
		schedule.chooseScreen();		
		break;
	case CHOOSE_DATE:
		schedule.chooseDate();
		break;
	case CHOOSE_MOVIE:
		schedule.chooseMovie();
		break;
	case INPUT_TIME:
		schedule.inputTime();
		break;
	case REGISTER_SCHEDULE:
		if (schedule.screen.number == 0)
		{
			cout << "�󿵰��� �������� �ʾҽ��ϴ�.\n";
		}
		else if (schedule.date.getValue() == 0)
		{
			cout << "������ �������� �ʾҽ��ϴ�.\n";
		}
		else if (schedule.movie.code == 0)
		{
			cout << "��ȭ�� �������� �ʾҽ��ϴ�.\n";
		}
		else if (schedule.startTime == 0)
		{
			cout << "�� �ð��� �Է����� �ʾҽ��ϴ�.\n";
		}
		else
		{
			return FUNCTION_SUCCESS;
		}
		system("pause");
	}

	return setSchedule(schedule);
}
