#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	enum ScheduleManagerFunction
	{
		SET_SCREEN = 1,
		SET_DATE,
		SET_MOVIE,
		SET_TIME,
		REGISTER_SCHEDULE,
	};

	for (Schedule schedule;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� ���\n"
			"\n";

		if (0 != schedule.screen.getNumber()
			|| 0 != schedule.date.getValue()
			|| 0 != schedule.movie.getCode()
			|| 0 != schedule.getStartTime())
		{
			cout << "�� ������\n";
			schedule.show();
			cout << endl;
		}

		cout <<
			"1. �󿵰� ����\n"
			"2. ��¥ ����\n"
			"3. ��ȭ ����\n"
			"4. �ð� ����\n"
			"5. �� ������ ���\n"
			"0. ����\n"
			"\n"
			"����: ";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
			continue;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case SET_SCREEN:
				setScreen(schedule.screen);
				continue;
			case SET_DATE:
				setDate(schedule.date);
				continue;
			case SET_MOVIE:
				setMovie(schedule.movie);
				continue;
			case SET_TIME:
				cout << endl;
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
				else
				{
					setTime(schedule);
					continue;
				}
				system("pause");
				continue;
			case REGISTER_SCHEDULE:
				if (0 == schedule.getStartTime())
				{
					cout << "�� �ð��� �Է����� �ʾҽ��ϴ�.\n";
					system("pause");
					continue;
				}
			}
		}

		SQLWCHAR scheduleSql[BUFSIZ];
		swprintf_s(scheduleSql, L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (?, ?, ?, ?, ?, ?);",
			schedule.date.getValue());
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.getValue(), schedule.screen.getNumber(), schedule.getStartTime(),
			schedule.screen.getNumber());

		if (SQL_SUCCESS == schedule.bindParameter()
			&& SQL_SUCCESS == schedule.execute(MDF_SCHEDULE, scheduleSql)
			&& SQL_SUCCESS == schedule.execute(MDF_SEAT, seatSql))
		{
			schedule.initialize();
			cout << "�� ������ ��� �Ǿ����ϴ�.\n";
		}
		else
		{
			cout << "�� ���� ����� �����߽��ϴ�.\n";
		}
		system("pause");
	}
}
