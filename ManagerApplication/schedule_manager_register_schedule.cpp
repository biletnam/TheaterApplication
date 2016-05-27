#include "schedule_manager.h"
#include <vector>

void ScheduleManager::registerSchedule()
{
	enum ScheduleManagerFunction
	{
		SCHEDULE_REGISTER = 1,
		CHOOSE_SCREEN,
		CHOOSE_DATE,
		CHOOSE_MOVIE,
		INPUT_TIME,
	};

	for (;;)
	{
		Schedule schedule(dbHelper);
		FNRETURN choice;
		do
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
				"1. �� ������ ���\n"
				"2. �󿵰� ����\n"
				"3. ��¥ ����\n"
				"4. ��ȭ ����\n"
				"5. �ð� ����\n"
				"0. ����\n";

			choice = inputInteger();
			switch (choice)
			{
			case CHOOSE_SCREEN:
				schedule.chooseScreen();
			case CHOOSE_DATE:
				schedule.chooseDate();
				break;
			case CHOOSE_MOVIE:
				schedule.chooseMovie();
				break;
			case INPUT_TIME:
				schedule.inputTime();
				break;
			case FUNCTION_CANCEL:
				return;
			}
		} while (choice != SCHEDULE_REGISTER);

		SQLWCHAR saleInfoSql[BUFSIZ];
		swprintf_s(saleInfoSql,	L""
			"INSERT INTO d%d "
			"(movie_code, movie_title, age, start_time, end_time, screen) "
			"VALUES (%d, ?, %d, %d, %d, %d);",
			schedule.date.getValue, 
			schedule.movie.code, schedule.movie.age,
			schedule.startTime,	schedule.endTime,
			schedule.screen.number);
		SQLCancel(dbHelper.getStmt(MDF_SALE_INFO));
		SQLBindParameter(dbHelper.getStmt(MDF_SALE_INFO), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_WVARCHAR,
			BUFSIZ, 0, schedule.movie.title, 0, NULL);
		
		SQLWCHAR seatSql[BUFSIZ];
		swprintf_s(seatSql, L"SELECT * INTO d%ds%dt%d FROM screen%d;",
			schedule.date.value, schedule.screen.number, schedule.startTime, schedule.screen.number);
		
		SQLCancel(dbHelper.getStmt(MDF_SEAT));
		if (SQL_SUCCESS == SQLExecDirect(dbHelper.getStmt(MDF_SALE_INFO), saleInfoSql, SQL_NTS)
			&& SQL_SUCCESS == SQLExecDirect(dbHelper.getStmt(MDF_SEAT), seatSql, SQL_NTS))
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