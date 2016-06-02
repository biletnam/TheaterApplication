#include "schedule_manager.h"

void ScheduleManager::checkAndModifySchedule()
{
	Schedule schedule;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� Ȯ�� / ����\n";

		if (0 != schedule.screen.getNumber()
			|| 0 != schedule.date.getValue())
		{
			cout << "\n�� ���� ����\n";
			schedule.show();
		}
				
		if (0 == schedule.date.getValue())
		{
			cout << "\n���� ����";
			Date::getToday().bindParameter();
			SQLRETURN ret = schedule.date.bindCol();
			schedule.date.prepare(L"SELECT date FROM date WHERE date_value>?;");
			switch (schedule.date.choose())
			{
			case FUNCTION_NULL:
				cout << "\n��ϵ� �� �������� �����ϴ�.\n";
				system("pause");
			case FUNCTION_CANCEL:
			case FUNCTION_ERROR:
				return;
			}
			continue;
		}
		else if (0 == schedule.screen.getNumber())
		{
			cout << "\n�󿵰� ����\n";
			schedule.screen.bindCol(MDF_THEATER, SCREEN_NUMBER);
			schedule.screen.prepare(L"SELECT number FROM screen;");
			switch (schedule.screen.choose())
			{
			case FUNCTION_NULL:
				cout << "\n��ϵ� ���� ������ �����ϴ�.\n";
				system("pause");
				return;
			case FUNCTION_CANCEL:
				schedule.date.initialize();
			}
			continue;
		}

		SQLWCHAR sql[BUFSIZ];
		swprintf_s(sql, L""
			"SELECT id, movie_code, movie_title, age, start_time, end_time "
			"FROM d%d "
			"WHERE screen=? "
			"ORDER BY start_time ASC;",
			schedule.date.getValue());

		schedule.screen.bindParameter(MDF_SCHEDULE, SCREEN_NUMBER);
		schedule.bindCol();
		schedule.prepare(sql);

		switch (schedule.choose())
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			modifySchedule(schedule);
			break;
		case FUNCTION_NULL:
			cout << "��ϵ� �� ������ �����ϴ�\n";
			system("pause");
		case FUNCTION_ERROR:
		default:
			schedule.initialize();
		}
	}
}