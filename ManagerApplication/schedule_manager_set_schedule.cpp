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
	for (;;)
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

		int8_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return FUNCTION_CANCEL;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case FUNCTION_CANCEL:
				return FUNCTION_CANCEL;
			case CHOOSE_SCREEN:
				schedule.chooseScreen();
				continue;
			case CHOOSE_DATE:
				schedule.chooseDate();
				continue;
			case CHOOSE_MOVIE:
				schedule.chooseMovie();
				continue;
			case INPUT_TIME:
				schedule.inputTime();
				continue;
			case REGISTER_SCHEDULE:
				if (0 == schedule.screen.getNumber())
				{
					cout << "�󿵰��� �������� �ʾҽ��ϴ�.\n";
				}
				else if (0 == schedule.date.getValue())
				{
					cout << "������ �������� �ʾҽ��ϴ�.\n";
				}
				else if (0 == schedule.movie.getCode())
				{
					cout << "��ȭ�� �������� �ʾҽ��ϴ�.\n";
				}
				else if (schedule.time.getStartTime() == 0)
				{
					cout << "�� �ð��� �Է����� �ʾҽ��ϴ�.\n";
				}
				else
				{
					return FUNCTION_SUCCESS;
				}
				system("pause");
				continue;
			}
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
