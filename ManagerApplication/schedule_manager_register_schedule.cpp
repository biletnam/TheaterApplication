#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	enum ScheduleManagerFunction
	{
		CHOOSE_SCREEN = 1,
		CHOOSE_DATE,
		CHOOSE_MOVIE,
		INPUT_TIME,
		REGISTER_SCHEDULE,
	};

	Schedule schedule;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� ���\n"
			"\n"
			"�� ������\n";
		schedule.show();

		cout <<
			"1. �󿵰� ����\n"
			"2. ��¥ ����\n"
			"3. ��ȭ ����\n"
			"4. �ð� ����\n"
			"5. �� ������ ���\n"
			"0. ����\n";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case CHOOSE_SCREEN:
				schedule.chooseScreen();
				continue;
			case CHOOSE_DATE:
				schedule.date.choose();
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
					break;;
				}
				system("pause");
				continue;
			}
			break;
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
			system("pause");
		}


		SQLWCHAR saleInfoSql[BUFSIZ];

		swprintf_s(saleInfoSql, L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (?, ?, ?, ?, ?, ?);",
			schedule.date.getValue());
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_CODE);
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_TITLE);
		schedule.movie.bindParameter(MDF_SALE_INFO, MOVIE_AGE);
		schedule.time.bindParameter(MDF_SALE_INFO, START_TIME);
		schedule.time.bindParameter(MDF_SALE_INFO, END_TIME);
		schedule.screen.bindParameter(MDF_SALE_INFO, SCREEN_NUMBER);
		
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.getValue(), schedule.screen.getNumber(), schedule.time.getStartTime(), 
			schedule.screen.getNumber());
		
		if (SQL_SUCCESS == schedule.execute(MDF_SALE_INFO, saleInfoSql)
			&& SQL_SUCCESS == schedule.execute(MDF_SEAT, seatSql))
		{
			cout << "�������� ��� �Ǿ����ϴ�.\n";
		}
		else
		{
			cout << "������ ����� �����߽��ϴ�.\n";
		}
		system("pause");
	}
}